#include "Sound.h"

FMOD_RESULT F_CALLBACK myDSPCallback(FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels) 
{
    FMOD_RESULT result;
    char name[256];
    unsigned int userdata;
    FMOD::DSP *thisdsp = (FMOD::DSP *)dsp_state->instance; 

    /* 
        This redundant call just shows using the instance parameter of FMOD_DSP_STATE to 
        call a DSP information function. 
    */
    result = thisdsp->getInfo(name, 0, 0, 0, 0);
    //ERRCHECK(result);

    result = thisdsp->getUserData((void **)&userdata);
    //ERRCHECK(result);

    /*
        This loop assumes inchannels = outchannels, which it will be if the DSP is created with '0' 
        as the number of channels in FMOD_DSP_DESCRIPTION.  
        Specifying an actual channel count will mean you have to take care of any number of channels coming in,
        but outputting the number of channels specified. Generally it is best to keep the channel 
        count at 0 for maximum compatibility.
    */
    for (unsigned int samp = 0; samp < length; samp++) 
    { 
        /*
            Feel free to unroll this.
        */
        for (int chan = 0; chan < *outchannels; chan++)
        {
            /* 
                This DSP filter just halves the volume! 
                Input is modified, and sent to output.
            */
            outbuffer[(samp * *outchannels) + chan] = inbuffer[(samp * inchannels) + chan];

			if(samp > length/8)
				outbuffer[(samp * *outchannels) + chan] += inbuffer[((samp-length/8) * inchannels) + chan] * 0.2f;
        }
    } 

    return FMOD_OK; 
} 


FMOD_RESULT F_CALLBACK myLowPass(FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels) 
{
    FMOD_RESULT result;
    char name[256];
    unsigned int userdata;
    FMOD::DSP *thisdsp = (FMOD::DSP *)dsp_state->instance; 

    /* 
        This redundant call just shows using the instance parameter of FMOD_DSP_STATE to 
        call a DSP information function. 
    */
    result = thisdsp->getInfo(name, 0, 0, 0, 0);
    //ERRCHECK(result);

    result = thisdsp->getUserData((void **)&userdata);
    //ERRCHECK(result);

    /*
        This loop assumes inchannels = outchannels, which it will be if the DSP is created with '0' 
        as the number of channels in FMOD_DSP_DESCRIPTION.  
        Specifying an actual channel count will mean you have to take care of any number of channels coming in,
        but outputting the number of channels specified. Generally it is best to keep the channel 
        count at 0 for maximum compatibility.
    */
    for (unsigned int samp = 0; samp < length; samp++) 
    { 
        /*
            Feel free to unroll this.
        */
        for (int chan = 0; chan < *outchannels; chan++)
        {
            /* 
                This DSP filter just halves the volume! 
                Input is modified, and sent to output.
            */
            outbuffer[(samp * *outchannels) + chan] = inbuffer[(samp * inchannels) + chan];

			if(samp > length/8)
				outbuffer[(samp * *outchannels) + chan] += inbuffer[((samp-length/8) * inchannels) + chan] * 0.2f;
        }
    } 

    return FMOD_OK; 
} 


FMOD_RESULT F_CALLBACK myHighPass(FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels) 
{
    FMOD_RESULT result;
    char name[256];
    unsigned int userdata;
    FMOD::DSP *thisdsp = (FMOD::DSP *)dsp_state->instance; 

    /* 
        This redundant call just shows using the instance parameter of FMOD_DSP_STATE to 
        call a DSP information function. 
    */
    result = thisdsp->getInfo(name, 0, 0, 0, 0);
    //ERRCHECK(result);

    result = thisdsp->getUserData((void **)&userdata);
    //ERRCHECK(result);

    /*
        This loop assumes inchannels = outchannels, which it will be if the DSP is created with '0' 
        as the number of channels in FMOD_DSP_DESCRIPTION.  
        Specifying an actual channel count will mean you have to take care of any number of channels coming in,
        but outputting the number of channels specified. Generally it is best to keep the channel 
        count at 0 for maximum compatibility.
    */
    for (unsigned int samp = 0; samp < length; samp++) 
    { 
        /*
            Feel free to unroll this.
        */
        for (int chan = 0; chan < *outchannels; chan++)
        {
            /* 
                This DSP filter just halves the volume! 
                Input is modified, and sent to output.
            */
            outbuffer[(samp * *outchannels) + chan] = inbuffer[(samp * inchannels) + chan];

			if(samp > length/8)
				outbuffer[(samp * *outchannels) + chan] += inbuffer[((samp-length/8) * inchannels) + chan] * 0.2f;
        }
    } 

    return FMOD_OK; 
} 


FMOD_RESULT F_CALLBACK MyEcoPass(FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels) 
{
    FMOD_RESULT result;
    char name[256];
    unsigned int userdata;
    FMOD::DSP *thisdsp = (FMOD::DSP *)dsp_state->instance; 

    /* 
        This redundant call just shows using the instance parameter of FMOD_DSP_STATE to 
        call a DSP information function. 
    */
    result = thisdsp->getInfo(name, 0, 0, 0, 0);
    //ERRCHECK(result);

    result = thisdsp->getUserData((void **)&userdata);
    //ERRCHECK(result);

    /*
        This loop assumes inchannels = outchannels, which it will be if the DSP is created with '0' 
        as the number of channels in FMOD_DSP_DESCRIPTION.  
        Specifying an actual channel count will mean you have to take care of any number of channels coming in,
        but outputting the number of channels specified. Generally it is best to keep the channel 
        count at 0 for maximum compatibility.
    */
    for (unsigned int samp = 0; samp < length; samp++) 
    { 
        /*
            Feel free to unroll this.
        */
        for (int chan = 0; chan < *outchannels; chan++)
        {
            /* 
                This DSP filter just halves the volume! 
                Input is modified, and sent to output.
            */
            outbuffer[(samp * *outchannels) + chan] = inbuffer[(samp * inchannels) + chan];

			if(samp > length/8)
				outbuffer[(samp * *outchannels) + chan] += inbuffer[((samp-length/8) * inchannels) + chan] * 0.2f;
        }
    } 

    return FMOD_OK; 
} 

Sound::Sound()
{
	channel = 0;
	//echo channelEcho = 0;
}

Sound::~Sound()
{
	result = sound1->release();
	result = sound2->release();
	result = mastergroup->removeDSP(customDSP);
    result = customDSP->release();
    //ERRCHECK(result);
}

void Sound::Initialize(FMOD::System *fmodsystem, char* filename)
{
	fmodSystem = fmodsystem;
	result = fmodSystem->createSound(filename, FMOD_LOOP_NORMAL, 0, &sound1);

	result = fmodSystem->createSound("Sounds/aint_I_right.mp3", FMOD_LOOP_NORMAL, 0, &sound2); //Modify this one
	switchSoundint = 1;
	//ERRCHECK(result);
	
	FMOD_DSP_DESCRIPTION dspdesc;
	memset(&dspdesc, 0, sizeof(dspdesc));
    
	//DSP
	strncpy(dspdesc.name, "custom DSP unit", sizeof(dspdesc.name));
	dspdesc.version = 0x00010000;
	dspdesc.numinputbuffers = 1;
	dspdesc.numoutputbuffers = 1;
	dspdesc.read = myDSPCallback;
	dspdesc.userdata = (void *)0x12345678; 

	result = fmodSystem->createDSP(&dspdesc, &customDSP); 
	//ERRCHECK(result); 

	result = customDSP->setBypass(true);
    //ERRCHECK(result);

    result = fmodSystem->getMasterChannelGroup(&mastergroup);
    //ERRCHECK(result);

    result = mastergroup->addDSP(0, customDSP, 0);
    //ERRCHECK(result);
    
}

void Sound::Play()
{
	result = fmodSystem->playSound(sound1, 0, false, &channel);
	//echo result = fmodSystem->playSound(sound1, 0, false, &channelEcho); //echotest
    //ERRCHECK(result);
}

void Sound::Update()
{
	if (buttonInput->GetMPressed())
		result = customDSP->setBypass(false);
	else
		result = customDSP->setBypass(true);

}

void Sound::CalculateSoundLevel(float soundVector[3],float listenerVector[3], float direction[3],float upDirection[3], float maxDist)
{
	float right = 0, left = 0;
	float dot,abs;
	float distance, normalizedDistance, cresult[3];
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
		crossProduct(direction,upDirection,cresult);
		normalize(cresult,cresult);

		dot = cresult[0]*soundCamVector[0] + cresult[1]*soundCamVector[1] + cresult[2]*soundCamVector[2];

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
	//echo channelEcho->setMixLevelsOutput(right * 0.5, left * 0.5,0,0,0,0,0,0);
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

void Sound::SwitchSounds()
{
	channel->getPosition(&index,FMOD_TIMEUNIT_MS);
	channel->stop();
	//echo channelEcho->stop();
	if (switchSoundint == 1)
	{
		result = fmodSystem->playSound(sound1, 0, false, &channel);
		//echo result = fmodSystem->playSound(sound2, 0, false, &channelEcho);
		switchSoundint = 2;
		result = customDSP->setBypass(false);
	}
	else
	{
		result = fmodSystem->playSound(sound1, 0, false, &channel);
		//echo result = fmodSystem->playSound(sound1, 0, false, &channelEcho);
		result = customDSP->setBypass(true);
		switchSoundint = 1;
	}
	
	channel->setPosition(index,FMOD_TIMEUNIT_MS);
	//echo channel->setPosition(index-10,FMOD_TIMEUNIT_MS);
	/*
	if (buttonInput->GetMPressed() == true)
	{
		channel->stop();
		channelEcho->stop();
	}

	if (buttonInput->GetNPressed() == true)
	{
		channelEcho->stop();
	}
	*/
    //ERRCHECK(result);
	//switchSoundint = 0;
}
