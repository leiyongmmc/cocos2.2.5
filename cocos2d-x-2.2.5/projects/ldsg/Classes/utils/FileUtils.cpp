#include "Utils/FileUtils.h"

#include <string>

#include "cocos2d.h"

USING_NS_CC;

namespace FileUtils
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#define _SplitCh	'\\'
#define _SplitStr	"\\"
#else
#define _SplitCh	'/'
#define _SplitStr	"/"
#endif

	void JoinPath(std::string &pre, const std::string &path)
	{
		if (pre.size() > 0 && *pre.rbegin() == _SplitCh)
		{
			pre += path;
		}
		else
		{
			pre += _SplitStr + path;
		}


#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		for (std::string::iterator pos = pre.begin(); pos != pre.end(); ++pos)
		{
			if ('/' == *pos)
			{
				*pos = '\\';
			}
		}

#else
		for (std::string::iterator pos = pre.begin(); pos != pre.end(); ++pos)
		{
			if ('\\' == *pos)
			{
				*pos = '/';
			}
		}

#endif
	}

	std::string FileUtils::GetFileByName(const char *filePath)
	{
		const char *content = CCString::createWithContentsOfFile(filePath)->getCString();
		CCLog("%s", content);
		if (content)
		{
			return content;
		}

		return "";
	}
}
