/*
 * SoundRecorder.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Gyy
 *      Bps_rate = (num_channels) * (1 sample in bytes) * (analog_rate) =
 *      (1 frame) * (analog_rate) = ( 2 channels ) * (2 bytes/sample) * (44100 samples/sec)
 *      = 2*2*44100 = 176400 Bytes/sec
 */

#ifndef SOUNDRECORDER_H_
#define SOUNDRECORDER_H_
#define ROUNDS 10
#include <string>
#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <iostream>
#include <stdint.h>
#include "CreateFile.h"
#include "UploadFile.h"
#include "ErrorLog.h"
class SoundRecorder : public CreateFile{
public:
	SoundRecorder(bool record, bool runAlways);
	~SoundRecorder();
private:
	int getSoundDevice();
	bool recordFiles = false;
	char deviceAddr[64];
	std::string device;
	unsigned int frequency = 16000;
	unsigned int samples;
	char *buffer;
	unsigned int memsize = 0;
	int channels = 1;
	int buffer_frames = 0;
	int initSound();
	void initBuffer();
	void freeBuffer();
	void readSound();
	int dev = 0;
	//for getting device open for recording
	snd_pcm_hw_params_t *hw_params;
	snd_pcm_t *capture_handle;
	snd_pcm_format_t format = SND_PCM_FORMAT_S16_LE;
	//for getting information about sound devices
	snd_ctl_t * cardHandle;
	snd_ctl_card_info_t *cardInfo;
	UploadFile upp;
	ErrorLog *err;
};

#endif /* SOUNDRECORDER_H_ */
