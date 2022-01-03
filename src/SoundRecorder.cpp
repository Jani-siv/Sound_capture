/*
 * SoundRecorder.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: Gyy
 *      https://www.cnblogs.com/lifan3a/articles/5566614.html
 */

#include "SoundRecorder.h"

SoundRecorder::SoundRecorder(bool record, bool runAlways) {
	// TODO Auto-generated constructor stub
ErrorLog logi;
this->err = &logi;
std::cout<<"object is created"<<std::endl;
this->recordFiles = record;
//try open default device
if ((this->getSoundDevice()) == 0)
{
	this->buffer_frames = 512 * 32;
	this->memsize = this->buffer_frames * 2;

this->initSound();
		if (this->channels == 2)
			{
			this->memsize = this->memsize * 4;
			}
this->initBuffer();
int stop = ROUNDS;
if (this->recordFiles == false)
{
	stop = 1;
}
for (int i = 0; i < stop; i++)
{

this->readSound();
}
}
else
{
	this->err->newError("error init device");
	exit(-1);
}
}

SoundRecorder::~SoundRecorder() {
	// TODO Auto-generated destructor stub
	snd_pcm_close (this->capture_handle);
	snd_config_update_free_global();
	this->freeBuffer();
	std::cout<<"object is deleted"<<std::endl;
}

void SoundRecorder::readSound()
{
	int err;

	std::cout<<"start capturing"<<std::endl;

	    if ((err = snd_pcm_readi (this->capture_handle, this->buffer, this->buffer_frames)) != this->buffer_frames) {
	      this->err->newError("read from audio interface failed");
	      exit (1);
	    }


//	std::cout<<"end capturing"<<std::endl;
//	std::cout<<"writing wav file"<<std::endl;
	std::string filename =  createWavFile(buffer,this->memsize, this->channels);
//	std::cout<<"created file: "<<filename<<std::endl;
	this->upp.sendFile(filename, this->recordFiles);
}

void SoundRecorder::initBuffer()
{
	this->buffer = (char*) malloc(this->memsize+1);
	memset(this->buffer,0x00,this->memsize);
}
void SoundRecorder::freeBuffer()
{
	free(this->buffer);
}
int SoundRecorder::initSound()
{
	int err;
	//open device for recording mode
	std::cout<<"card addr: "<<this->deviceAddr<<std::endl;
	std::cout<<"device: "<<this->dev<<std::endl;
	if ((err = snd_pcm_open (&this->capture_handle,this->deviceAddr,SND_PCM_STREAM_CAPTURE,0)) < 0) {
	    this->err->newError("cannot open audio device");
	    exit (1);
	  }
	//reserve memory for params
	if ((err = snd_pcm_hw_params_malloc (&this->hw_params)) < 0) {
		this->err->newError("cannot allocate hardware parameter structure");
	    exit (1);
	  }
	if ((err = snd_pcm_hw_params_any(this->capture_handle, hw_params)) < 0) {
		this->err->newError("cannot initialize harware parameter structure");
	    exit (1);
	  }
	if ((err = snd_pcm_hw_params_set_access (this->capture_handle, this->hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
		this->err->newError("cannot set access type");
	    exit (1);
	  }
	if ((err = snd_pcm_hw_params_set_format (this->capture_handle, this->hw_params, this->format)) < 0) {
		this->err->newError("cannot set sample format");
	    exit (1);
	  }
	if ((err = snd_pcm_hw_params_set_rate_near (this->capture_handle, this->hw_params, &this->frequency, 0)) < 0) {
		this->err->newError("cannot set sample rate");
	    exit (1);
	  }
	if ((err = snd_pcm_hw_params_set_channels (this->capture_handle, this->hw_params, 1)) < 0) {
			this->channels = 2;
			if ((err = snd_pcm_hw_params_set_channels (this->capture_handle, this->hw_params, 2)) < 0){
				this->err->newError("cannot set channel count");
	    exit (1);
	  }
	}

	if ((err = snd_pcm_hw_params (this->capture_handle, this->hw_params)) < 0) {
		this->err->newError("cannot set parameters");
	    exit (1);
	  }
	snd_pcm_hw_params_free (this->hw_params);
	if ((err = snd_pcm_prepare (this->capture_handle)) < 0) {
		this->err->newError("cannot prepare audio interface for use");
	    exit (1);
	  }
	fprintf(stdout, "audio interface prepared\n");
	return 0;
}

int SoundRecorder::getSoundDevice()
{
	int cardNum = -1;
	int err;
	for(;;)
	{
		if ((err = snd_card_next(&cardNum)) < 0)
		{
			this->err->newError("cat't get card number");
		}
		if (cardNum < 0)
		{
			break;
		}
		{
			char str[64];
			sprintf(str,"hw:%i", cardNum);
			if ((err = snd_ctl_open(&this->cardHandle, str, 0)) < 0)
			{
				this->err->newError("can't open card");
				continue;
			}
		}
		{
			snd_ctl_card_info_alloca(&this->cardInfo);
			if ((err = snd_ctl_card_info(this->cardHandle,this->cardInfo)) < 0)
			{
				this->err->newError("Can't get information from card");
			}
			else
			{
				std::cout<<"Card "<<cardNum<<" = "<<snd_ctl_card_info_get_name(this->cardInfo)<<std::endl;
				std::string name = snd_ctl_card_info_get_name(this->cardInfo);
				if (name.compare(0,3,"bcm") != 0)
				{
					std::cout<<"found first not bcm "<<name<<std::endl;
					//close handle for changing mode

					snd_ctl_close(this->cardHandle);
					sprintf(this->deviceAddr,"hw:%i,0", cardNum);
					return 0;
				}
			}
		}
	}

	return 0;
}
