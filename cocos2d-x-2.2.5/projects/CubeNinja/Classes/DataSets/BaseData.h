// ���ݱ�Ļ���
#ifndef __FUNS_BASE_DATA_H__
#define __FUNS_BASE_DATA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

#include "Utils/StringUtils.h"
#include "Utils/FileUtils.h"

struct SBaseData
{
	// ���ܣ����������ļ����ݳ�ʼ�����ݽṹ
	// ���������������ļ�
	virtual void InitData(std::string fileData) = 0;
};

#endif