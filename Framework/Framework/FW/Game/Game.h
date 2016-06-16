#ifndef  _GAME_H_
#define  _GAME_H_

#include <SDL.h>
#include <vector>
#include "../Manager/Texture/TextureManager.h"
#include "../State/GameStateMachine.h"
#include "../Object/GameObject.h"
#include "../Manager/SoundManager.h"

class Game
{
public:

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void quit();

	static Game* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}
	SDL_Renderer* get_Renderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	Game();

	static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;

	int m_currentFrame;
	int m_currentFrame2;

	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;
};
#define TheGame Game::Instance()

#endif // ! 