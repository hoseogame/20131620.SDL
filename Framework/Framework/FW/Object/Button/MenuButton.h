#ifndef __MENU_BUTTON__
#define __MENU_BUTTON__

#include "../../Object/SDLGameObject.h"

enum  Button_State
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams);
	MenuButton(const LoaderParams* pParams, void(*callback)());

	bool m_bReleased;

	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void(*m_callback)();
};

#endif