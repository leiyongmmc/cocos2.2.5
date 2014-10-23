#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

#include "Log/Log.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
	CCEGLView* eglView = CCEGLView::sharedOpenGLView();
	eglView->setViewName("CubeNinja");

	//�������ļ�
	bool isNoConfig = true;
	//�Ƿ�򿪿���̨
	bool bOpenConsole = false;
	
	if (CCFileUtils::sharedFileUtils()->isFileExist("config.xml"))
	{
		CCDictionary *strings = CCDictionary::createWithContentsOfFile("config.xml");
		if (strings)
		{
			int  screenWidth = strings->valueForKey("screenWidth")->intValue();
			int  screenHeight = strings->valueForKey("screenHeight")->intValue();
			float  screenScale = strings->valueForKey("screenScale")->floatValue();
			
			// ���ƿ���
			bOpenConsole = strings->valueForKey("ConsoleOpenFlag")->boolValue(); 
			// ��־�������̨����
			bool bDebugOutputFlag = strings->valueForKey("LogOutputFlag")->boolValue(); 
			Log::GetInstance()->SetOutputFlag(bDebugOutputFlag);
			// ��־��������̿���
			bool bDebugWriteFlag = strings->valueForKey("LogWriteFlag")->boolValue(); 
			Log::GetInstance()->SetWriteFlag(bDebugWriteFlag);

			if (screenWidth > 0 && screenHeight > 0)
			{
				isNoConfig = false;
				eglView->setFrameSize(screenWidth, screenHeight);
				if (screenScale > 0)
				{
					eglView->setFrameZoomFactor(screenScale);
				}
			}
		}
	}
	
	if (isNoConfig)
	{
		eglView->setFrameSize(960, 640);
		//eglView->setFrameSize( 1136, 640 );
		//eglView->setFrameSize(1024, 768);
		//eglView->setFrameSize( 2048, 1536 );
		//eglView->setFrameSize( 1920, 1080 );
		//eglView->setFrameSize(480, 320);
	}

	if (bOpenConsole)
	{
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
	}

	int ret = CCApplication::sharedApplication()->run();

	if (bOpenConsole)
		FreeConsole();
	return ret;
}
