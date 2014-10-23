// –‘ƒ‹≤‚ ‘
#ifndef __FUNS_STOP_WATCH_H__
#define __FUNS_STOP_WATCH_H__

#include "cocos2d.h"

#include <string>

class StopWatch
{
public:
	StopWatch(const char* info = NULL);
	void Start(const char* info = NULL);
	void End();
private:
	cocos2d::cc_timeval mTimeVal;
	std::string mInfo;
};

#endif