#pragma once
#include "SoundSystem.hpp"

SoundSystem::SoundSystem()
{
	//Initialize();
}
SoundSystem::~SoundSystem()
{
	result = fmodSystem->close();
    //ERRCHECK(result);
    result = fmodSystem->release();
    //ERRCHECK(result);
}
void SoundSystem::Initialize()
{
	result = FMOD::System_Create(&fmodSystem);
	//ERRCHECK(result);

	result = fmodSystem->getVersion(&version);
	//ERRCHECK(result);

	result = fmodSystem->init(32, FMOD_INIT_NORMAL, 0);
	//ERRCHECK(result);

}

void SoundSystem::Update()
{
	fmodSystem->update();
}


Sound::Sound()
{
	channel = 0;
}

Sound::~Sound()
{
	result = sound->release();
    //ERRCHECK(result);
}

void Sound::Initialize(FMOD::System *fmodsystem, char* filename)
{
	
	fmodSystem = fmodsystem;
	result = fmodSystem->createSound(filename, FMOD_LOOP_NORMAL, 0, &sound);
	//ERRCHECK(result);
}

void Sound::Play()
{
	result = fmodSystem->playSound(sound, 0, false, &channel);
    //ERRCHECK(result);
}

void Sound::CalculateSoundLevel(float soundVector[3],float listenerVector[3], float direction[3],float upDirection[3], float maxDist)
{
	float right = 0, left = 0;
	float dot,abs;
	float distance, normalizedDistance, result[3];
	distance = sqrt(pow(soundVector[0]-listenerVector[0],2)+pow(soundVector[1]-listenerVector[1],2)+pow(soundVector[2]-listenerVector[2],2));
	if (distance < maxDist)
	{
		float soundCamVector[3];
		soundCamVector[0] = soundVector[0]-listenerVector[0];
		soundCamVector[1] = soundVector[1]-listenerVector[1];
		soundCamVector[2] = soundVector[2]-listenerVector[2];
		normalize(soundCamVector,soundCamVector);

		normalize(direction,direction);
		normalize(upDirection,upDirection);
		crossProduct(direction,upDirection,result);
		normalize(result,result);

		dot = result[0]*soundCamVector[0] + result[1]*soundCamVector[1] + result[2]*soundCamVector[2];

		if(dot < -1 || dot > 1)
		{
			int adsg = 0;
		}
		
		/*left = 1 + dot;
		right = 1 - dot;*/
		left = sqrt(1 + dot);
		right = sqrt(1 - dot);

		float volumeScaling = 1 - distance/maxDist;

		left *= volumeScaling;
		right *= volumeScaling;

	}


	if (left < 100 && left >= 0 && right < 100 && right >= 0)
		SetStereoratio(right,left);
	/*else if(left < 10 && left >= 0)
		SetStereoratio(left,0);
	else if(right < 10 && right >= 0)
		SetStereoratio(0,right);*/
	else
		SetStereoratio(0,0);
}

void Sound::SetStereoratio(float right,float left)
{
	channel->setMixLevelsOutput(left, right,0,0,0,0,0,0);
}

void Sound::crossProduct(float v1[], float v2[], float vR[]) {
  vR[0] =   ( (v1[1] * v2[2]) - (v1[2] * v2[1]) );
  vR[1] = - ( (v1[0] * v2[2]) - (v1[2] * v2[0]) );
  vR[2] =   ( (v1[0] * v2[1]) - (v1[1] * v2[0]) );
}

void Sound::normalize(float v1[], float vR[]) {
  float fMag;

  fMag = sqrt( pow(v1[0], 2) +
               pow(v1[1], 2) +
               pow(v1[2], 2)
             );
  if(fMag != 0)
  {
	vR[0] = v1[0] / fMag;
	vR[1] = v1[1] / fMag;
	vR[2] = v1[2] / fMag;
  }
}