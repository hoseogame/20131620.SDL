#include "../../FW/Game/Game.h"
#include "MenuState.h"
#include "CreditState.h"
#include "HelpState.h"
#include "../../FW/Object/GameObject.h"
#include "../../FW/Manager/Load/LoaderParams.h"
#include "../../FW/Object/SDLGameObject.h"
#include "../../FW/Manager/Texture/TextureManager.h"
#include "../../FW/Object/Button/MenuButton.h"
#include "../../FW/Manager/SoundManager.h"

const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
	for ( int i = 0; i < m_gameObjects.size(); i++ )
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for ( int i = 0; i < m_gameObjects.size(); i++ )
	{
		m_gameObjects[i]->draw();
	}
}
bool MenuState::onEnter()
{
	if ( !TheTextureManager->load( "assets/Sprites/Main.png", "main", TheGame->get_Renderer() ) )
	{
		return false;
	}

	GameObject* mainBackground = new SDLGameObject( new LoaderParams( 0, 0, 1280, 720, "main" ) );
	m_gameObjects.push_back( mainBackground );

	if ( TheSoundManager::Instance()->getSound()["main"] == NULL )
	{
		TheSoundManager::Instance()->init();
		if ( !TheSoundManager::Instance()->createSound( "assets/Sounds/MainSound.wma", "main", FMOD_LOOP_NORMAL ) )
		{
			return false;
		}

		TheSoundManager::Instance()->play( "main" );
	}

	if ( !TheTextureManager->load( "assets/Sprites/credit.png", "credit", TheGame->get_Renderer() ) )
	{
		return false;
	}

	if ( !TheTextureManager->load( "assets/Sprites/exit.png", "exit", TheGame->get_Renderer() ) )
	{
		return false;
	}

	if ( !TheTextureManager->load( "assets/Sprites/help.png", "help", TheGame->get_Renderer() ) )
	{
		return false;
	}

	if ( !TheTextureManager->load( "assets/Sprites/start.png", "start", TheGame->get_Renderer() ) )
	{
		return false;
	}


	GameObject* start = new MenuButton( new LoaderParams( 900, 400, 299, 70, "start" ) );
	GameObject* credit = new MenuButton( new LoaderParams( 900, 470, 299, 70, "credit" ), s_menuToCredit );
	GameObject* help = new MenuButton( new LoaderParams( 900, 540, 299, 70, "help" ), s_menuToHelp );
	GameObject* exit = new MenuButton( new LoaderParams( 900, 610, 299, 70, "exit" ), s_exitFromMenu );

	m_gameObjects.push_back( start );
	m_gameObjects.push_back( credit );
	m_gameObjects.push_back( help );
	m_gameObjects.push_back( exit );

	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	for ( int i = m_gameObjects.size() - 1; i >= 0; i-- )
	{
		m_gameObjects[i]->clean();
		m_gameObjects.pop_back();
	}
	TheTextureManager->clearFromTextureMap( "main" );
	TheTextureManager->clearFromTextureMap( "start" );
	TheTextureManager->clearFromTextureMap( "credit" );
	TheTextureManager->clearFromTextureMap( "help" );
	TheTextureManager->clearFromTextureMap( "exit" );
	
	m_gameObjects.clear();
	return true;
}

void MenuState::s_menuToPlay()
{
	//TheGame::Instance()->getStateMachine()->changeState(new PlayState());
	std::cout << "Play button clicked\n";
}

void MenuState::s_menuToHelp()
{
	TheGame->getStateMachine()->changeState( new HelpState );
}

void MenuState::s_menuToCredit()
{
	TheGame->getStateMachine()->changeState( new CreditState );
}

void MenuState::s_exitFromMenu()
{
	TheGame->quit();
}