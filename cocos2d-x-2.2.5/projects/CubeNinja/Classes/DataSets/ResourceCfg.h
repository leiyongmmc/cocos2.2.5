// 游戏中的一些资源

#ifndef __FUNS_RESOURCE_CFG_H__
#define __FUNS_RESOURCE_CFG_H__

#include "DataSets/BaseData.h"

struct SResourceData
{
	std::string key;	// 名称
	std::string res;	// 资源
};

struct SResourceDataContainer : public SBaseData
{
	std::vector<SResourceData*>				dataList;
	std::map<std::string, SResourceData*>	dataMap;

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

			SResourceData *data = new SResourceData();
			data->key = rowData[0];
			data->res = rowData[1];

			dataList.push_back(data);
			dataMap[data->key] = data;
		}
	}
};

#endif