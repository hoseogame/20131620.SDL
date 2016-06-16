#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = nullptr;

void SoundManager::init()
{
	FMOD_System_Create(&m_System);
	FMOD_System_Init(m_System, 32, FMOD_INIT_NORMAL, NULL);
}

bool SoundManager::createSound(const char* fileName, std::string key, FMOD_MODE mode)
{
	FMOD_SOUND* pSound;
	FMOD_System_CreateSound(m_System, fileName, mode, 0, &pSound);

	m_Sound[key] = pSound;
	
	if (pSound != nullptr)
		return true;
	else
		return false;
}

void SoundManager::play(std::string key)
{
	FMOD_System_PlaySound(m_System, m_Sound[key], NULL, false, &m_Channel);
}

void SoundManager::clean()
{
	for (int i = 0; m_key[i] != ""; i++)
	{
		m_Sound.erase(m_key[i]);
	}

	FMOD_System_Close(m_System);
	FMOD_System_Release(m_System);
}