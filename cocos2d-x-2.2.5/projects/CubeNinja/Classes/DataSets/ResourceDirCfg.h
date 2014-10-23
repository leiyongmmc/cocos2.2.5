#ifndef __FUNS_RESOURCE_DIR_CFG_H__
#define __FUNS_RESOURCE_DIR_CFG_H__

#include "DataSets/BaseData.h"

struct SResourceDirData
{
	std::string key;	// Ãû³Æ
	std::string dir;	// ×ÊÔ´
};

struct SResourceDirDataContainer : public SBaseData
{
	std::vector<SResourceDirData*>				dataList;
	std::map<std::string, SResourceDirData*>	dataMap;

	void InitData(std::string fileData)
	{
		std::vector<std::string> rowDatas = StringUtils::Split(fileData, "\n");
		for (int i = 0; i < rowDatas.size(); i++)
		{
			if (i < 2)
				continue;

			std::vector<std::string> rowData = StringUtils::Split(rowDatas[i], "	");
			if (rowData.size() <= 1)
				continue;

			SResourceDirData *data = new SResourceDirData();
			data->key = rowData[0];
			data->dir = rowData[1];

			dataList.push_back(data);
			dataMap[data->key] = data;
		}
	}
};

#endif