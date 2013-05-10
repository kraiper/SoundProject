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

void Sound::CalculateSoundLevel(float soundVector[3],float listenerVector[3], float direction[3], float maxDist)
{
	float right = 1, left = 1;
	float distance, normalizedDistance, result[3];
	distance = sqrt(pow(soundVector[0]-listenerVector[0],2)+pow(soundVector[1]-listenerVector[1],2)+pow(soundVector[2]-listenerVector[2],2));
	//if (distance < maxDist)
	//{
		float soundCamVector[3];
		soundCamVector[0] = soundVector[0]-listenerVector[0];
		soundCamVector[1] = soundVector[1]-listenerVector[1];
		soundCamVector[2] = soundVector[2]-listenerVector[2];
		normalize(soundCamVector,soundCamVector);
		crossProduct(soundCamVector, direction, result);
		normalize(result,result);
		normalizedDistance = sqrt(pow(result[0],2)+pow(result[1],2)+pow(result[2],2));
		left = sqrt(2/(2*(cos(normalizedDistance) + sin(normalizedDistance))));
		right = sqrt(2/(2*(cos(normalizedDistance) - sin(normalizedDistance))));
	//}

	if (left < 1 && left > 0 && right < 1 && right > 0)
		SetStereoratio(right,left);
	else
		SetStereoratio(1,1);
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