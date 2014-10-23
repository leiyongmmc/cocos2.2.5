#include "Sound/SoundManager.h"

SoundManager *SoundManager::sInstance = NULL;

SoundManager *SoundManager::GetInstance()
{
	return sInstance;
}

void SoundManager::PurgeInstance()
{
	delete sInstance;
	sInstance = NULL;
}

