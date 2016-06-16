#include "Game.h"
#include "../../Game/State/MenuState.h"
#include "../Manager/Input/InputHandler.h"

Game* Game::s_pInstance = nullptr;

Game::Game()
{
	m_pWindow = 0;
	m_pRenderer = 0;
	m_bRunning = false;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// �ʱ�ȭ �����ϸ�, window ����
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// window ������ �����ϸ�, renderer ���� 
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);    // �� (R,G,B,A) ���� 
	}
	else
	{
		return false; // sdl could not initialize
	}

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	m_bRunning = true;

	return true; // sdl initialize
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);  // �����츦 ������ ������ ����  
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);   // ������ ���̱�
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	exit(1);
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		//m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
}

void Game::quit()
{
	m_bRunning = false;
}