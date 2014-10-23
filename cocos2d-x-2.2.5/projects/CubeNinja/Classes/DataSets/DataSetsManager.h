// 数据表的管理类
// 一次加载所有
#ifndef __FUNS_DATA_SETS_MANAGER_H__
#define __FUNS_DATA_SETS_MANAGER_H__

#include "DataSets/DataInclude.h"


class DataSetsManager
{
public:
	static DataSetsManager *GetInstance();
	static void PurgeInstance();
	const char* GetResource(std::string key);
	float GetGameVariable(std::string key);
private:
	DataSetsManager();
	~DataSetsManager();
	// 初始化数据对象
	void RegistrationData();
	// 读取配置文件加载加载到内存中
	void LoadConfigData(const char* dirPath);
public:
	SGameVariableContainer		*mGameVariableContainer;
	SResolutionDataContainer	*mResolutionDataContainer;
	SResourceDataContainer		*mResourceDataContainer;
	SResourceDirDataContainer	*mResourceDirDataContainer;
private:
	std::map<std::string, SBaseData*> mContainerMap;

	static DataSetsManager *sInstance;
};

#endif