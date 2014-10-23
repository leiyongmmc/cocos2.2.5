// …˘“Ùπ‹¿Ì¿‡

#ifndef __FUNS_SOUND_MANAGER_H__
#define __FUNS_SOUND_MANAGER_H__

#include "cocos2d.h"

class SoundManager : public cocos2d::CCObject
{
public:
	static SoundManager *GetInstance();
	static void PurgeInstance();

	void PlayBgm();
	void StopBgm();
	void PauseBgm();
	void ResumeBgm();
	void RewindBgm();
	void IsBgmPlaying();
	void SetBgmVolume(float vol);
	float GetBgmVolume() const;

	void PlayEffect();
	void StopEffect();
	void SetEffectVolume(float vol);
	float GetEffectVolume() const;
private:
	SoundManager();
	~SoundManager();
private:
	static SoundManager *sInstance;
};

#endif 