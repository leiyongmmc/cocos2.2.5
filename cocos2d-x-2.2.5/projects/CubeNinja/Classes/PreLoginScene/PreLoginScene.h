#ifndef __FUNS_PRE_LOGIN_SCENE_H__
#define __FUNS_PRE_LOGIN_SCENE_H__

#include "cocos2d.h"

class PreLoginScene : public cocos2d::CCScene
{
public:
	virtual bool init();
	CREATE_FUNC(PreLoginScene);
	void OnExitScene();
};

#endif