#pragma once
#include "singletonBase.h"
#include <map>

#include "inc/fmod.hpp"

#pragma comment (lib, "lib/fmodex_vc.lib")

using namespace FMOD;

#define SOUNDBUFFER 20
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER (SOUNDBUFFER + EXTRACHANNELBUFFER)

class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<wstring, Sound**> arrSounds;
	typedef map<wstring, Sound**>::iterator arrSoundsIter;
	typedef map<wstring, Channel**> arrChannels;
	typedef map<wstring, Channel**>::iterator arrChannelsIter;

	typedef map<unsigned int, Sound**> arrSoundsInt;
	typedef map<unsigned int, Sound**>::iterator arrSoundsIterInt;
	typedef map<unsigned int, Channel**> arrChannelsInt;
	typedef map<unsigned int, Channel**>::iterator arrChannelsIterInt;

	System* _system;
	Sound** _sound;
	Channel** _channel;

	arrSounds _mTotalSounds;
	arrSoundsInt _mTotalSoundsInt;


public:
	HRESULT init();
	void release();
	void update();

	//==========================================================================문자열 키
	void addSound(wstring keyName, wstring soundName, bool bgm, bool loop);
	void play(wstring keyName, float volume = 1.0f);
	void stop(wstring keyName);
	void pause(wstring keyName);
	void resume(wstring keyName);

	void allStop();

	bool isPlaySound(wstring keyName);
	bool isPauseSound(wstring keyName);

	//==========================================================================번호 키

	void addSound(unsigned int keyName, wstring soundName, bool bgm, bool loop);
	void play(unsigned int keyName, float volume = 1.0f);
	void stop(unsigned int keyName);
	void pause(unsigned int keyName);
	void resume(unsigned int keyName);

	void allStopInt();

	bool isPlaySound(unsigned int keyName);
	bool isPauseSound(unsigned int keyName);
	
	soundManager();
	~soundManager();
};

