#include "../../FW/Game/Game.h"
#include "MenuState.h"
#include "HelpState.h"
#include "../../FW/Object/GameObject.h"
#include "../../FW/Manager/Load/LoaderParams.h"
#include "../../FW/Object/SDLGameObject.h"
#include "../../FW/Manager/Texture/TextureManager.h"
#include "../../FW/Object/Button/MenuButton.h"
#include "../../FW/Manager/SoundManager.h"

const std::string HelpState::s_menuID = "HELP";

void HelpState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void HelpState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool HelpState::onEnter()
{
	if (!TheTextureManager->load("assets/Sprites/HelpState.png", "HelpState", TheGame->get_Renderer()))
	{
		return false;
	}

	if (!TheTextureManager->load("assets/Sprites/back.png", "Back", TheGame->get_Renderer()))
	{
		return false;
	}

	GameObject* mainBackground = new SDLGameObject(new LoaderParams(0, 0, 1280, 720, "HelpState"));
	m_gameObjects.push_back(mainBackground);

	GameObject* Back = new MenuButton(new LoaderParams(1100, 50, 136, 70, "Back"), s_exitFromHelp);
	
	m_gameObjects.push_back(Back);

	std::cout << "entering MenuState\n";
	return true;
}
bool HelpState::onExit()
{
	for (int i = m_gameObjects.size() - 1; i >= 0; i--)
	{
		m_gameObjects[i]->clean();
		m_gameObjects.pop_back();
	}
	TheTextureManager->clearFromTextureMap( "HelpState" );
	TheTextureManager->clearFromTextureMap( "Back" );
	m_gameObjects.clear();
	return true;
}

void HelpState::s_exitFromHelp()
{
	TheGame->getStateMachine()->changeState(new MenuState);
}