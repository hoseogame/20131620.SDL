#pragma once

#include "../../FW/State/GameState.h"

class GameObject;

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }

private:
	static void s_menuToPlay();
	static void s_menuToHelp();
	static void s_menuToCredit();
	static void s_exitFromMenu();
	static const std::string s_menuID;

	int obj_size;

	std::vector<GameObject*> m_gameObjects;
};
