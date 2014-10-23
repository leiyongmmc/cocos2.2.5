#include "AppDelegate.h"

#include "SimpleAudioEngine.h"

#include "PreLoginScene/PreLoginScene.h"

#include "DataSets/DataSetsManager.h"

USING_NS_CC;

using namespace CocosDenshion;

#if CC_TARGET_PLATFORM != CC_PLATFORM_WIN32
#include <dirent.h>
#include <sys/stat.h>
#endif

// 制作时画布的大小
#define CAVSW 960
#define CAVSH 640

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
	SimpleAudioEngine::end();

	// clear manager
}

bool AppDelegate::applicationDidFinishLaunching() 
{
	// initial path 
	CCFileUtils::sharedFileUtils()->getWritablePath();

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	// datasets loading
	DataSetsManager *pDatasetsMgr = DataSetsManager::GetInstance();

    // create a scene. it's an autorelease object

	PreLoginScene *pScene = PreLoginScene::create();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() 
{
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() 
{
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}