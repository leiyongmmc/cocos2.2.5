// ��Ϸ�е�һЩ����������

#ifndef __FUNS_GAME_VARIABLE_CFG_H__
#define __FUNS_GAME_VARIABLE_CFG_H__

#include "DataSets/BaseData.h"

struct SGameVariable
{
	std::string key;	// ��������
	float		value;	// ����ֵ
	std::string desc;	// ��������
};

struct SGameVariableContainer : public SBaseData
{
	std::vector<SGameVariable*>				dataList;
	std::map<std::string, SGameVariable*>	dataMap;

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

			SGameVariable *data = new SGameVariable();
			data->key	= rowData[0];
			data->value = atof(rowData[1].c_str());
			data->desc	= rowData[2];

			dataList.push_back(data);
			dataMap[data->key] = data;
		}
	}
};
#endif