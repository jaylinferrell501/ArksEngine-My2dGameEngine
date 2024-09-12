#pragma once
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "Components/Component.h"
 
using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename tType>
inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;
using ComponentArray = std::array<ArksEngineComponents::Component*, maxComponents>;

namespace ArksEngine
{
	// The GameObject class, representing an individual game object that can have multiple components.
	class GameObject
	{
		bool mIsActive = true;
		std::string mName = "Unknown";
		std::string mTag = "Unknown";

		std::vector<std::unique_ptr<ArksEngineComponents::Component>> mComponents;
		ComponentArray mComponentArray = {};

	public:
		// Updates all components attached to this entity.
		void Update(double deltaTime) const
		{
			for (auto& component : mComponents)
				component->Update(deltaTime);
		}
		// Renders all components attached to this entity at a offset.
		void Render(float xOffset) const
		{
			for (auto& component : mComponents)
				component->Render(xOffset);
		}

		// Checks if entity is active
		[[nodiscard]] bool IsActive() const { return mIsActive; }
		void Destroy() { mIsActive = false; }

		// Getters/Setters
		std::string GetName() { return mName; }
		std::string GetTag() const { return mTag; }
		void SetName(std::string name) { mName = std::move(name); }
		void SetTag(std::string tag) { mTag = std::move(tag); }

		// Check to see if GameObject has this component.
		template<typename tType>
		[[nodiscard]] bool HasComponent() const
		{
			auto ptr(mComponentArray[GetComponentTypeID<tType>()]);

			return ptr != nullptr;
		}
		// Adds a new component of type tType to the entity and initializes it.
		template<typename tType, typename... tArgs>
		tType&AddComponent(tArgs&&... mArgs)
		{
			tType* component(new tType(std::forward<tArgs>(mArgs)...));
			component->mGameObj = this;
			std::unique_ptr<ArksEngineComponents::Component> uPtr{ component };
			mComponents.emplace_back(std::move(uPtr));

			mComponentArray[GetComponentTypeID<tType>()] = component;

			component->Init();
			return *component;
		}
		// Retrieves the component of type tType from the entity, if it exists.
		template<typename tType>
		tType& GetComponent() const
		{
			auto ptr(mComponentArray[GetComponentTypeID<tType>()]);
			return *static_cast<tType*>(ptr);

			// Example: entity.GetComponent<TransformComponent>().SetPosition(0, 0, 100, 200);
		}
	};

}


