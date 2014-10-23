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

#define LOCAL_VERSION_RELATIVE "version"


#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#define _SplitCh	'\\'
#define _SplitStr	"\\"
#else
#define _SplitCh	'/'
#define _SplitStr	"/"
#endif

static void JoinPath(std::string &pre, const std::string &path)
{
	if(pre.size() > 0 && *pre.rbegin() == _SplitCh)
	{
		pre += path;
	}
	else
	{
		pre += _SplitStr + path;
	}


#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	for(std::string::iterator pos=pre.begin();pos!=pre.end();++pos)
	{
		if( '/' == *pos )
		{
			*pos = '\\';
		}
	}

#else
	for(std::string::iterator pos=pre.begin();pos!=pre.end();++pos)
	{
		if( '\\' == *pos )
		{
			*pos = '/';
		}
	}

#endif
}


static bool GetVersionRelative(std::string &verPathString)
{
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
	JoinPath(path, LOCAL_VERSION_RELATIVE);

	verPathString = path;

	return true;
}

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

	// setup 
	setupSearchPath();

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

void AppDelegate::setupSearchPath()
{
	std::vector<std::string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();

	CCLog("*******%s",searchPaths.at(0).c_str());

	std::string versionPath;
	/*if(GetVersionRelative(versionPath))
	{
	if( std::find(searchPaths.begin(), searchPaths.end(),versionPath) == searchPaths.end() )
	{
	std::vector<std::string>::iterator iter = searchPaths.begin();
	searchPaths.insert(iter, versionPath);

	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
	}
	}*/


	// 添加资源搜索目录
	const char *dirs[] = {
		"data","music","panel","uires"
	};
		
	for ( int i = sizeof(dirs)/sizeof(dirs[0])-1; i >= 0; i-- )
	{
		CCFileUtils::sharedFileUtils()->addSearchPath(dirs[i]);
	}

	CCFileUtils::sharedFileUtils()->setSearchPaths( searchPaths );

	for (int i = 0; i < searchPaths.size();i++)
	{
		CCLog("*******%s",CCFileUtils::sharedFileUtils()->getSearchPaths().at(i).c_str());
	}
		
}