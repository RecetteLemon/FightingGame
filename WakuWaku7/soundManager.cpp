#include "stdafx.h"
#include "soundManager.h"


soundManager::soundManager()
:_system(NULL),
_sound(NULL),
_channel(NULL)
{
}


soundManager::~soundManager()
{
}


HRESULT soundManager::init()
{
	System_Create(&_system);
	
	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);

	_sound = new Sound*[TOTALSOUNDBUFFER];
	_channel = new Channel*[TOTALSOUNDBUFFER];

	ZeroMemory(_sound, sizeof(Sound*) * TOTALSOUNDBUFFER);
	ZeroMemory(_channel, sizeof(Channel*) * TOTALSOUNDBUFFER);

	return S_OK;
}
void soundManager::release()
{
	if ((_channel != NULL || _sound != NULL))
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; i++)
		{
			if (_channel != NULL)
			{
				_channel[i]->stop();
			}

			if (_sound != NULL)
			{
				_sound[i]->release();
			}
		}
	}

	//메모리 지우기
	SAFE_DELETE_ARRAY(_channel);
	SAFE_DELETE_ARRAY(_sound);

	//시스템 닫기 
	if (_system != NULL)
	{
		_system->release();
		_system->close();
	}
}
void soundManager::update()
{
}

void soundManager::addSound(wstring keyName, wstring soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)
		{
			_system->createStream((const char*)soundName.c_str(), FMOD_LOOP_NORMAL | FMOD_UNICODE, 0, &_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound((const char*)soundName.c_str(), FMOD_LOOP_NORMAL | FMOD_UNICODE, 0, &_sound[_mTotalSounds.size()]);
		}
	}
	else
	{
		if (bgm)
		{
			_system->createStream((const char*)soundName.c_str(), FMOD_DEFAULT | FMOD_UNICODE, 0, &_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound((const char*)soundName.c_str(), FMOD_DEFAULT | FMOD_UNICODE, 0, &_sound[_mTotalSounds.size()]);

		}
	}

	_mTotalSounds.insert(make_pair(keyName, &_sound[_mTotalSounds.size()]));
}
void soundManager::play(wstring keyName, float volume)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_system->playSound(FMOD_CHANNEL_FREE, _sound[count], false, &_channel[count]);
			_channel[count]->setVolume(volume);
			break;
		}
	}
}

void soundManager::stop(wstring keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}

void soundManager::allStop()
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		_channel[count]->stop();
	}
}

void soundManager::pause(wstring keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(wstring keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}

bool soundManager::isPlaySound(wstring keyName)
{
	bool isPlay;
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

bool soundManager::isPauseSound(wstring keyName)
{
	bool isPause;
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{

			_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}



//===================================================int Key=============================
void soundManager::addSound(unsigned int keyName, wstring soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)
		{
			_system->createStream((const char*)soundName.c_str(), FMOD_LOOP_NORMAL | FMOD_UNICODE, 0, &_sound[_mTotalSoundsInt.size()]);
		}
		else
		{
			_system->createSound((const char*)soundName.c_str(), FMOD_LOOP_NORMAL | FMOD_UNICODE, 0, &_sound[_mTotalSoundsInt.size()]);
		}
	}
	else
	{
		if (bgm)
		{
			_system->createStream((const char*)soundName.c_str(), FMOD_DEFAULT | FMOD_UNICODE, 0, &_sound[_mTotalSoundsInt.size()]);
		}
		else
		{
			_system->createSound((const char*)soundName.c_str(), FMOD_DEFAULT | FMOD_UNICODE, 0, &_sound[_mTotalSoundsInt.size()]);
		}
	}

	_mTotalSoundsInt.insert(make_pair(keyName, &_sound[_mTotalSoundsInt.size()]));
}
void soundManager::play(unsigned int keyName, float volume)
{
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_system->playSound(FMOD_CHANNEL_FREE, _sound[count], false, &_channel[count]);
			_channel[count]->setVolume(volume);
			break;
		}
	}
}

void soundManager::stop(unsigned int keyName)
{
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}


void soundManager::allStopInt()
{
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		_channel[count]->stop();
	}
}

void soundManager::pause(unsigned int keyName)
{
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(unsigned int keyName)
{
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}

bool soundManager::isPlaySound(unsigned int keyName)
{
	bool isPlay;
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

bool soundManager::isPauseSound(unsigned int keyName)
{
	bool isPause;
	arrSoundsIterInt iter = _mTotalSoundsInt.begin();

	int count = 0;

	for (iter; iter != _mTotalSoundsInt.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{

			_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}