// 声音配表
#ifndef __FUNS_SOUND_CFG_H__
#define __FUNS_SOUND_CFG_H__

#include "DataSets/BaseData.h"

struct SSoundData
{
	int			id;			// 声音编号
	std::string res;		// 资源路径
};

struct SSoundDataContainer : public SBaseData
{
	std::vector<SSoundData*>	dataList;
	std::map<int, SSoundData*>  dataMap;

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

			SSoundData *data = new SSoundData();
			data->id = atoi(rowData[0].c_str());
			data->res = rowData[1];

			dataList.push_back(data);
			dataMap[data->id] = data;
		}
	}
};


#endif