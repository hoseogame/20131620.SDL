#include "../../Manager/Input/InputHandler.h"
#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = MOUSE_OUT;
}

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
	SDLGameObject::drawFrame();
}

void MenuButton::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width) &&
		pMousePos->getX() > m_position.getX() &&
		pMousePos->getY() < (m_position.getY() + m_height) &&
		pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = MOUSE_OVER;
			m_callback();
		}
	}
	else m_currentFrame = MOUSE_OUT;
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}