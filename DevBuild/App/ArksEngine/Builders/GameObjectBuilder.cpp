#include "GameObjectBuilder.h"
#include "../Utillities/tinyxml2.h"
#include <cstdlib>
#include "../Core.h"
#include "../Components/ControllerComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicsComponent.h"
#include "../Components/SpriteComponent.h"
#include "../GameObject.h"
#include "../GameObjectManager.h"
#include "../LuaSystem.h"
#include "../Components/ColliderComponent.h"
#include "../Components/ScriptComponent.h"
#include "../Components/HealthComponent.h"

ArksEngineBuilders::GameObjectBuilder::GameObjectBuilder(ArksEngine::Core* pOwner, ArksEngine::GameObjectManager* pManager)
	:m_pOwner(pOwner)
	,m_pEntityManager(pManager)
{
}

void ArksEngineBuilders::GameObjectBuilder::CreateGameObject(const char* pXml_File) const
{
	// Create a new entity and add it to the entity manager
	ArksEngine::GameObject& game_object(m_pEntityManager->AddGameObject());

	// Load the XML file
	tinyxml2::XMLDocument doc;
	doc.LoadFile(pXml_File);

	// Get the name of the entity from the XML file and set it
	const tinyxml2::XMLElement* elementTag = doc.FirstChildElement()->FirstChildElement();
	const char* pName = elementTag->GetText();
	game_object.SetName(pName);

	// Get the tag of the entity from the XML file and set it
	elementTag = doc.FirstChildElement("gameObject")->FirstChildElement()->NextSiblingElement();
	const char* pTag = elementTag->GetText();
	game_object.SetTag(pTag);

	// Move to the next element (the first component)
	elementTag = elementTag->NextSiblingElement();

	const tinyxml2::XMLElement* elementChild = elementTag;

	// Iterate through all component elements in the XML file
	while (elementTag)
	{
		// Get the component type
		const char* pComponentType = elementTag->Attribute("name");
		std::string componentType = pComponentType;

		// Handle each component type
		if (componentType == "TransformComponent")
		{
			// Get position, rotation, and scale values from the XML file
			// and add a TransformComponent to the entity with those values
			elementChild = elementTag->FirstChildElement();
			const char* pPositionX = elementChild->GetText();
			float positionX = atoi(pPositionX);

			elementChild = elementChild->NextSiblingElement();
			const char* pPositionY = elementChild->GetText();
			float positionY = atoi(pPositionY);

			elementChild = elementChild->NextSiblingElement();
			const char* pRotationX = elementChild->GetText();
			float rotationX = atoi(pRotationX);

			elementChild = elementChild->NextSiblingElement();
			const char* pRotationY = elementChild->GetText();
			float rotationY = atoi(pRotationY);

			elementChild = elementChild->NextSiblingElement();
			const char* pScaleX = elementChild->GetText();
			float scaleX = atoi(pScaleX);

			elementChild = elementChild->NextSiblingElement();
			const char* pScaleY = elementChild->GetText();
			float scaleY = atoi(pScaleY);

			game_object.AddComponent<ArksEngineComponents::TransformComponent>();
			game_object.GetComponent<ArksEngineComponents::TransformComponent>().SetPosition(positionX, positionY);
			game_object.GetComponent<ArksEngineComponents::TransformComponent>().SetRotation(rotationX, rotationY);
			game_object.GetComponent<ArksEngineComponents::TransformComponent>().SetScale(scaleX, scaleY);

		}
		else if (componentType == "SpriteComponent")
		{
			// Get the sprite filename from the XML file
			// and add a SpriteComponent to the entity with that filename
			elementChild = elementTag->FirstChildElement();
			const char* pFileName = elementChild->GetText();

			elementChild = elementChild->NextSiblingElement();
			const char* pNumberOfFrames = elementChild->GetText();
			int frames = atoi(pNumberOfFrames);

			elementChild = elementChild->NextSiblingElement();
			const char* pFrameSpeed = elementChild->GetText();
			int speed = atoi(pFrameSpeed);

			game_object.AddComponent<ArksEngineComponents::SpriteComponent>(m_pOwner, pFileName, frames, speed);

		}
		else if (componentType == "ColliderComponent")
		{
			// Get the width, height, and offsets from the XML file
			// and add a ColliderComponent to the entity with those values
			elementChild = elementTag->FirstChildElement();
			const char* pWidth = elementChild->GetText();
			int width = atoi(pWidth);

			elementChild = elementChild->NextSiblingElement();
			const char* pHeight = elementChild->GetText();
			int height = atoi(pHeight);

			elementChild = elementChild->NextSiblingElement();
			const char* pXOffset = elementChild->GetText();
			int xOffset = atoi(pXOffset);

			elementChild = elementChild->NextSiblingElement();
			const char* pYOffset = elementChild->GetText();
			int yOffset = atoi(pYOffset);

			game_object.AddComponent<ArksEngineComponents::ColliderComponent>(m_pOwner->GetRenderer());
			game_object.GetComponent<ArksEngineComponents::ColliderComponent>().SetWidth(width);
			game_object.GetComponent<ArksEngineComponents::ColliderComponent>().SetHeight(height);
			game_object.GetComponent<ArksEngineComponents::ColliderComponent>().SetXOffset(xOffset);
			game_object.GetComponent<ArksEngineComponents::ColliderComponent>().SetYOffset(yOffset);
		}
		else if (componentType == "PhysicsComponent")
		{
			// Get the speed value from the XML file
			// and add a PhysicsComponent to the entity with that value
			elementChild = elementTag->FirstChildElement();
			const char* pSpeed = elementChild->GetText();
			double speed = atoi(pSpeed);

			game_object.AddComponent<ArksEngineComponents::PhysicsComponent>(m_pOwner);
			game_object.GetComponent<ArksEngineComponents::PhysicsComponent>().SetSpeed(speed);
		}
		else if (componentType == "ControllerComponent")
		{
			// Add a ControllerComponent to the entity
			game_object.AddComponent<ArksEngineComponents::ControllerComponent>(m_pOwner->GetInput());
		}
		else if (componentType == "ScriptComponent")
		{
			m_pOwner->GetLuaSystem()->PushGameObject(m_pOwner->GetLuaSystem()->GetLuaState(), &game_object);

			// After you've pushed the GameObject, set it as a global variable in Lua
			m_pOwner->GetLuaSystem()->SetGlobal("GameObject", &game_object);

			game_object.AddComponent<ArksEngineComponents::ScriptComponent>(m_pOwner->GetLuaSystem());

			elementChild = elementTag->FirstChildElement();
			const char* pScript = elementChild->GetText();

			game_object.GetComponent<ArksEngineComponents::ScriptComponent>().AddScript(pScript);

			while (elementChild->NextSiblingElement())
			{
				elementChild = elementTag->NextSiblingElement();
				pScript = elementChild->GetText();
				game_object.GetComponent<ArksEngineComponents::ScriptComponent>().AddScript(pScript);
			}

		}
		else if(componentType == "HealthComponent")
		{
			game_object.AddComponent<ArksEngineComponents::HealthComponent>(m_pOwner);
		}


		// Move to the next sibling element (next component)
		elementTag = elementTag->NextSiblingElement();

	}
}
