#ifndef __FUNS_STRING_UTILS_H__
#define __FUNS_STRING_UTILS_H__

#include <vector>

class StringUtils
{
public:
	// ×Ö·û´®µÄÇÐ·Ö
	static std::vector<std::string> Split(const std::string &str, const std::string &flag);
};

#endif