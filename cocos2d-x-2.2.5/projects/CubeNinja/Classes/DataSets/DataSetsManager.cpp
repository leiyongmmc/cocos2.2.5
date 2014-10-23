#include "DataSets/DataSetsManager.h"

#include "cocos2d.h"

#include "Global/ResourceDir.h"

DataSetsManager *DataSetsManager::sInstance = NULL;

DataSetsManager *DataSetsManager::GetInstance()
{
	if (!sInstance)
	{
		sInstance = new DataSetsManager();
		sInstance->RegistrationData();
		sInstance->LoadConfigData(RESOURCE_DIR_DATA);
	}

	return sInstance;
}

void DataSetsManager::PurgeInstance()
{
	delete sInstance;
	sInstance = NULL;
}

const char* DataSetsManager::GetResource(std::string key)
{
	std::map<std::string, SResourceData*>::iterator iter = mResourceDataContainer->dataMap.find(key);
	if (iter != mResourceDataContainer->dataMap.end())
		return iter->second->res.c_str();

	return NULL;
}

float DataSetsManager::GetGameVariable(std::string key)
{
	std::map<std::string, SGameVariable*>::iterator iter = mGameVariableContainer->dataMap.find(key);
	if (iter != mGameVariableContainer->dataMap.end())
		return iter->second->value;

	return 0.0f;
}

DataSetsManager::DataSetsManager()
{
	mResolutionDataContainer = NULL;

	mContainerMap.clear();
}

DataSetsManager::~DataSetsManager()
{

}

void DataSetsManager::RegistrationData()
{
	mGameVariableContainer		= new SGameVariableContainer();
	mResolutionDataContainer	= new SResolutionDataContainer();
	mResourceDataContainer		= new SResourceDataContainer();

	mContainerMap["gamevariable.dat"]	= mGameVariableContainer;
	mContainerMap["resolution.dat"]		= mResolutionDataContainer;
	mContainerMap["resource.dat"]		= mResourceDataContainer;
}

void DataSetsManager::LoadConfigData(const char* dirPath)
{
	if (!dirPath)
		return;

	dirPath = "";

	std::map<std::string, SBaseData*>::iterator iter = mContainerMap.begin();
	for (iter; iter != mContainerMap.end(); ++iter)
	{
		std::string fileName = iter->first;
		char filePath[256] = {0};
		snprintf(filePath,sizeof(filePath),"%s%s",dirPath,fileName.c_str());
		std::string fileData = FileUtils::GetFileByName(filePath);

		iter->second->InitData(fileData);
	}
}