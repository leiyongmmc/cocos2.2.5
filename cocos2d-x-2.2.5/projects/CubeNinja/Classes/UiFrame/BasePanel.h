// 面板类基类
#ifndef __FUNS_BASE_PANEL_H__
#define __FUNS_BASE_PANEL_H__

#include "Global/Config.h"

class BasePanel : public cocos2d::CCObject
{
public:
	BasePanel();
	virtual ~BasePanel();
public:
	virtual const char* GetPanelName() = 0;
	virtual const char* GetPanelResPath() = 0;
	virtual void Init() = 0;
	virtual void OnShow() = 0;
	virtual void OnHide() = 0;
public:
	// 根据Json文件创建一个Widget
	virtual UIWidget* CreatePanel();
	UIWidget* GetPanel();
protected:
	UIWidget* mPanel;
};

#endif