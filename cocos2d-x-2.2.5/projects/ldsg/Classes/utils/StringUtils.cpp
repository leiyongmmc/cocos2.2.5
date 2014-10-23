#include "Utils/StringUtils.h"

std::vector<std::string> StringUtils::Split(const std::string &str, const std::string &flag)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	std::string dup = str;
	dup += flag;

	int size = dup.size();

	for (int i = 0; i < size; i++)
	{
		pos = dup.find(flag, i);
		if (pos < (std::string::size_type)size)
		{
			std::string s = dup.substr(i, pos - i);
			result.push_back(s);

			i = (pos + flag.size() - 1);
		}
	}

	return result;
}