#ifndef __SDL_GAME_OBJECT__
#define __SDL_GAME_OBJECT__

#include <string>
#include "GameObject.h"
#include "../Math/Vector2D.h"

class LoaderParams;

class SDLGameObject : public GameObject
{
public:
	SDLGameObject();
	virtual void draw();
	virtual void drawFrame();
	virtual void update();
	virtual void clean();
	virtual void load( const LoaderParams* pParams );

	SDLGameObject* gameObject;
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width, m_height;
	int m_currentRow, m_currentFrame;
	int m_numFrames;
	std::string m_textureID;
};

#endif