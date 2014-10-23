#include "PreLoginScene/PreLoginScene.h"

#include "LoginScene/LoginScene.h"

#include "DataSets/DataSetsManager.h"

USING_NS_CC;

bool PreLoginScene::init()
{
	bool ret = false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		
		CCDirector *director = CCDirector::sharedDirector();
		const CCSize &winSize = director->getWinSize();
		this->setContentSize(winSize);

		CCLayerColor *layer = CCLayerColor::create(ccc4(255, 255, 255, 255));
		layer->setContentSize(winSize);
		layer->setColor(ccWHITE);
		this->addChild(layer);

		CCSprite *logo = CCSprite::create("uires/Logo/logo.png"/*DataSetsManager::GetInstance()->GetResource("Studio_Logo")*/);
		logo->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		
		layer->addChild(logo);

		// ¶¯»­
		float fadeInTime = 0.5f;//DataSetsManager::GetInstance()->GetGameVariable("Logo_Fadein_Time");
		float fadeOutTime = 0.5f;//DataSetsManager::GetInstance()->GetGameVariable("Logo_Fadeout_Time");
		float stayTime = 1.0f;//DataSetsManager::GetInstance()->GetGameVariable("Logo_Stay_Time");

		CCArray* array = CCArray::create();
		array->addObject(CCFadeIn::create(fadeInTime));
		array->addObject(CCDelayTime::create(stayTime));
		array->addObject(CCFadeOut::create(fadeOutTime));
		array->addObject(CCCallFunc::create(this,callfunc_selector(PreLoginScene::OnExitScene)));
		CCSequence *seq = CCSequence::create(array);
		
		logo->runAction(seq);

		ret = true;
	} while (0);

	return ret;
}

void PreLoginScene::OnExitScene()
{
	LoginScene *scene = LoginScene::create();
	CCTransitionCrossFade *transScene = new CCTransitionCrossFade();
	transScene->initWithDuration(0.05f/*DataSetsManager::GetInstance()->GetGameVariable("Transition_Time")*/, scene);
	CCDirector::sharedDirector()->replaceScene(transScene);
}