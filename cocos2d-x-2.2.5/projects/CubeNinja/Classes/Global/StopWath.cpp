#include "Global/StopWath.h"

USING_NS_CC;

StopWatch::StopWatch(const char* info)
{
	Start(info);
}

void StopWatch::Start(const char* info)
{
	CCTime::gettimeofdayCocos2d(&mTimeVal, NULL);
	if (info)
	{
		mInfo = info;
	}
	else
	{
		mInfo = "";
	}
}

void StopWatch::End()
{
	cc_timeval now;
	double dt = CCTime::timersubCocos2d(&mTimeVal, &now) / 1000.0;
	CCLog("[Performance]:%s for %.3f\n", mInfo.c_str(), dt);
}