#include "Utils/FileUtils.h"

#include <string>

#include "cocos2d.h"
namespace FileUtils
{
	std::string FileUtils::GetFileByName(const char *filePath)
	{
		cocos2d::CCString *content = cocos2d::CCString::createWithContentsOfFile(filePath);
		if (content)
		{
			return content->getCString();
		}

		return "";
	}
}
