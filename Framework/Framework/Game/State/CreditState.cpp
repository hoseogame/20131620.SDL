#include "../../FW/Game/Game.h"
#include "CreditState.h"
#include "MenuState.h"
#include "../../FW/Object/GameObject.h"
#include "../../FW/Manager/Load/LoaderParams.h"
#include "../../FW/Object/SDLGameObject.h"
#include "../../FW/Manager/Texture/TextureManager.h"
#include "../../FW/Object/Button/MenuButton.h"
#include "../../FW/Manager/SoundManager.h"

const std::string CreditState::s_menuID = "CREDIT";

void CreditState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void CreditState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool CreditState::onEnter()
{
	if (!TheTextureManager->load("assets/Sprites/Developer.png", "Develop", TheGame->get_Renderer()))
	{
		return false;
	}

	GameObject* mainBackground = new SDLGameObject(new LoaderParams(0, 0, 1280, 720, "Develop"));
	m_gameObjects.push_back(mainBackground);


	if (!TheTextureManager->load("assets/Sprites/back.png", "Back", TheGame->get_Renderer()))
	{
		return false;
	}


	GameObject* Back = new MenuButton(new LoaderParams(1100, 50, 136, 70, "Back"), s_exitFromCredit);
	m_gameObjects.push_back(Back);

	std::cout << "entering MenuState\n";
	return true;
}
bool CreditState::onExit()
{
	for (int i = m_gameObjects.size() - 1; i >= 0; i--)
	{
		m_gameObjects[i]->clean();
		m_gameObjects.pop_back();
	}
	TheTextureManager->clearFromTextureMap( "Develop" );
	TheTextureManager->clearFromTextureMap( "Back" );
	m_gameObjects.clear();
	m_gameObjects.resize( 0 );
	return true;
}

void CreditState::s_exitFromCredit()
{
	TheGame->getStateMachine()->changeState(new MenuState);
}
