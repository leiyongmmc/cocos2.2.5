// 屏幕适配
#ifndef __FUNS_RESOLUTION_CFG_H__
#define __FUNS_RESOLUTION_CFG_H__

#include "DataSets/BaseData.h"

struct SResolutionData
{
	std::string		key;			// 关键字
	int				width;		// 宽度
	int				height;		// 高度
	std::string		dir;			// 资源目录
};

struct SResolutionDataContainer : public SBaseData
{
	std::vector<SResolutionData*>			dataList;
	std::map<std::string,SResolutionData*>  dataMap;

	void InitData(std::string fileData)
	{
		std::vector<std::string> rowDatas = StringUtils::Split(fileData,"\n");
		for (int i = 0; i < rowDatas.size(); i++)
		{
			if (i < 2)
				continue;

			std::vector<std::string> rowData = StringUtils::Split(rowDatas[i], "	");
			if (rowData.size() <= 1)
				continue;

			SResolutionData *data = new SResolutionData();
			data->key   = rowData[0];
			data->width = atoi(rowData[1].c_str());
			data->height= atoi(rowData[2].c_str());
			data->dir   = rowData[3];
			
			dataList.push_back(data);
			dataMap[data->key] = data;
		}
	}
};




#endif