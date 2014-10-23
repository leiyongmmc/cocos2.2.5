#ifndef __FUNS_UI_SCENE_OBJECT_H__
#define __FUNS_UI_SCENE_OBJECT_H__

template<class T>
class UISceneObject
{
public:
	UISceneObject() :mPanel(NULL)
	{}
	void ShowThis(int showType)
	{

	}

	void HideThis(int hideType)
	{
	
	}

	void MakePanel()
	{
		if (!mPanel)
		{
			mPanel = new T();
		}
	}

	operator bool() const
	{
		return mPanel != NULL;
	}

	T* operator->()
	{
		return mPanel;
	}
protected:
	T *mPanel;
};

#endif
