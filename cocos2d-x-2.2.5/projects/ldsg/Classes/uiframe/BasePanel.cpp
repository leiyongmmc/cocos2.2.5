#include "UiFrame/BasePanel.h"

#include "Global/StopWath.h"

BasePanel::BasePanel() :
mPanel(NULL)
{}

BasePanel::~BasePanel()
{

}

UIWidget *BasePanel::CreatePanel()
{
	if (!mPanel)
	{
		StopWatch sw(CCString::createWithFormat("[Loading json and create widget:%s]", GetPanelName())->getCString());
		mPanel = GUIReader::shareReader()->widgetFromJsonFile(GetPanelResPath());
		sw.End();

		sw.Start(CCString::createWithFormat("[Init panel object:%s]", GetPanelName())->getCString());
		Init();
		sw.End();
	}

	return mPanel;
}

UIWidget *BasePanel::GetPanel()
{
	return mPanel;
}
