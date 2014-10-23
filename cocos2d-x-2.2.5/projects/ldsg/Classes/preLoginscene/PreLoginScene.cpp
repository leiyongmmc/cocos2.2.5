#include "PreLoginScene/PreLoginScene.h"

#include "LoginScene/LoginScene.h"

#include "global/GlobalResource.h"

#include "datasets/DataSetsManager.h"

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

		CCSprite *logo = CCSprite::create(LOGO_URL);
		if (logo)
		{
			logo->setPosition(ccp(winSize.width / 2, winSize.height / 2));
			layer->addChild(logo);
			
			// ¶¯»­
			float fadeInTime = DataSetsManager::GetInstance()->GetGameVariable("Logo_Fadein_Time");
			float fadeOutTime = DataSetsManager::GetInstance()->GetGameVariable("Logo_Fadeout_Time");
			float stayTime = DataSetsManager::GetInstance()->GetGameVariable("Logo_Stay_Time");

			CCArray* array = CCArray::create();
			array->addObject(CCFadeIn::create(fadeInTime));
			array->addObject(CCDelayTime::create(stayTime));
			array->addObject(CCFadeOut::create(fadeOutTime));
			array->addObject(CCCallFunc::create(this,callfunc_selector(PreLoginScene::OnExitScene)));
			CCSequence *seq = CCSequence::create(array);

			logo->runAction(seq);
		}

		ret = true;
	} while (0);

	return ret;
}

void PreLoginScene::OnExitScene()
{
	LoginScene *scene = LoginScene::create();
	CCTransitionCrossFade *transScene = new CCTransitionCrossFade();
	transScene->initWithDuration(DataSetsManager::GetInstance()->GetGameVariable("Transition_Time"), scene);
	CCDirector::sharedDirector()->replaceScene(transScene);
}