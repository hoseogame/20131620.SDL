#ifndef __SOUND_MANAGER__
#define __SOUND_MANAGER__

#include <iostream>
#include <fmod.h>
#include <map>
#include <string>

class SoundManager
{
public:
	void init();
	void play(std::string key);
	void clean();
	bool createSound(const char* fileName, std::string key, FMOD_MODE mode);
	FMOD_SYSTEM* getSystem() { return m_System; }
	std::map<std::string, FMOD_SOUND*> getSound() { return m_Sound; }

	static SoundManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new SoundManager();
		}
		return s_pInstance;
	}

private:
	static SoundManager* s_pInstance;

	FMOD_SYSTEM* m_System;
	std::map<std::string, FMOD_SOUND*> m_Sound; 
	std::string m_key[100];
	FMOD_CHANNEL* m_Channel;
};

typedef SoundManager TheSoundManager;

#endif