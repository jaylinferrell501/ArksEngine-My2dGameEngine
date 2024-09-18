#pragma once
#include <list>
#include <memory>
#include <string>

#include "GameObject.h"


namespace ArksEngine
{

	// The GameObjectManager class, responsible for managing the creation, updating, rendering, and destruction of entities.
	class GameObjectManager
	{

	public:
		// A container for storing all entities.
		std::list<std::unique_ptr<GameObject>> mGameObjects;

		// Updates all entities in the manager .
		void Update(double deltaTime) const;

		// Renders all entities in the manager at a Offset.
		void Render(float xOffset) const;

		void Render() const;

		// Removes entities that are not active from the manager.
		void Refresh();

		// Adds a new entity to the manager.
		GameObject& AddGameObject();

		GameObject* GetGameObject(const std::string& name) const; const

		// Clears all entities from the manager.
		void Clear(){mGameObjects.clear();}


	};
}



