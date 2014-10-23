#include "LoginScene/LoginScene.h"

#include "cocos-ext.h"

bool LoginScene::init()
{
	bool ret = false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		cocos2d::ui::UILayer *layer = cocos2d::ui::UILayer::create();
		layer->addWidget(cocos2d::extension::GUIReader::shareReader()->widgetFromJsonFile("Panel/Loading_Resource_Panel.json"));
		
		this->addChild(layer);
		
		ret = true;
	} while (0);

	return ret;
}