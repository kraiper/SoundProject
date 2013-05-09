#pragma once
#include "SoundSystem.hpp"


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

void Sound::CalculateSoundLevel(float soundVector[3],float listenerVector[3])
{
	float right = 1, left = 1;
	//Insert magic 3d stuff
	SetStereoratio(right,left);

}

void Sound::SetStereoratio(float right,float left)
{
	channel->setMixLevelsOutput(left, right,0,0,0,0,0,0);
}
