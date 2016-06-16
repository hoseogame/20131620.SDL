#ifndef __CREDIT_STATE__
#define __CREDIT_STATE__

#include "../../FW/State/GameState.h"

class GameObject;

class CreditState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

private:
	static void s_exitFromCredit();
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

#endif