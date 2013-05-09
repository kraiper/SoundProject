#pragma once
#include <fmod.hpp>
#include <string>

class SoundSystem
{
public:
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
	void CalculateSoundLevel(float[3], float[3]);
	//Insert filterfunktion
	
private:
	void SetStereoratio(float,float);//0-1.0f

	FMOD::System *fmodSystem;
	FMOD::Sound *sound;
    FMOD::Channel *channel;
	FMOD_RESULT  result;
};