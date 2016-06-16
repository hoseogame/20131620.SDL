#ifndef __GAMEOBJECTFACTORY__
#define __GAMEOBJECTFACTORY__

#include <iostream>
#include <string>
#include <map>
#include "../../Object/GameObject.h"

class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

class GameObjectFactory
{
public:
	bool registerType( std::string typeID, BaseCreator* pCreator )
	{
		std::map<std::string, BaseCreator*>::iterator it = m_creators.find( typeID );

		if ( it != m_creators.end() )
		{
			delete pCreator;
			return false;
		}

		m_creators[typeID] = pCreator;
		return true;
	}

	GameObject* create( std::string typeID )
	{
		std::map<std::string, BaseCreator*>::iterator it = m_creators.find( typeID );
		
		if ( it == m_creators.end() )
		{
			std::cout << "could not find " << typeID << "\n";
			return NULL;
		}
		BaseCreator* pCreator = (*it).second;
		return pCreator->createGameObject();
	}

private:
	std::map<std::string, BaseCreator*> m_creators;
};

#endif
