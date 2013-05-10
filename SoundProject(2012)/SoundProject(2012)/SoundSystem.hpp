#pragma once
#include <fmod.hpp>
#include <string>
#include "stdafx.h"

class SoundSystem
{
public:
	SoundSystem();
	~SoundSystem();
	void Initialize();
	void Update();
	FMOD::System *fmodSystem;
	
private:
	
	FMOD_RESULT  result;
	unsigned int version;

};

class Sound
{
public:
	Sound();
	~Sound();
	void Initialize(FMOD::System*, char*);
	void Play();
	void CalculateSoundLevel(float[3], float[3], float[3], float);
	//Insert filterfunktion
	void crossProduct(float[], float[], float[]);
	void normalize(float[], float[]) ;
	void SetStereoratio(float,float);//0-1.0f
private:
	

	FMOD::System *fmodSystem;
	FMOD::Sound *sound;
    FMOD::Channel *channel;
	FMOD_RESULT  result;
};