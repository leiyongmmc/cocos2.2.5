#include "LoginScene/LoginScene.h"

#include "cocos-ext.h"

bool LoginScene::init()
{
	bool ret = false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		cocos2d::ui::UILayer *layer = cocos2d::ui::UILayer::create();
		cocos2d::ui::UIWidget *widget = cocos2d::extension::GUIReader::shareReader()->widgetFromJsonFile("panel/test_panel.json");
		layer->addWidget(widget);
		
		this->addChild(layer);
		
		ret = true;
	} while (0);

	return ret;
}