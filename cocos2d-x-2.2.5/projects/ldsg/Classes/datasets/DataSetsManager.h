// ���ݱ�Ĺ�����
// һ�μ�������
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
	// ��ʼ�����ݶ���
	void RegistrationData();
	// ��ȡ�����ļ����ؼ��ص��ڴ���
	void LoadConfigData(const char* dirPath);
public:
	SGameVariableContainer		*mGameVariableContainer;
	SResolutionDataContainer	*mResolutionDataContainer;
	SResourceDataContainer		*mResourceDataContainer;
	SResourceDirDataContainer	*mResourceDirDataContainer;
	SSoundDataContainer			*mSoundDataContainer;
private:
	std::map<std::string, SBaseData*> mContainerMap;

	static DataSetsManager *sInstance;
};

#endif