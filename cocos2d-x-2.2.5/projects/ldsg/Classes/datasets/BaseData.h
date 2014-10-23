// 数据表的基类
#ifndef __FUNS_BASE_DATA_H__
#define __FUNS_BASE_DATA_H__

#include "cocos2d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

#include "Utils/StringUtils.h"

USING_NS_CC;

struct SBaseData
{
	// 功能：根据配置文件数据初始化数据结构
	// 参数：整个配置文件
	virtual void InitData(std::string fileData) = 0;
};

#endif