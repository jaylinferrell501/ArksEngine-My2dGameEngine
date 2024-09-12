#include "HealthComponent.h"
#include "../Event.h"
#include <any>
#include <iostream>
#include "../GameObject.h"
#include "../Core.h"
#include "../EventManager.h"

ArksEngineComponents::HealthComponent::HealthComponent(ArksEngine::Core* pOwner)
	:m_pOwner(pOwner)
{
}

void ArksEngineComponents::HealthComponent::Init()
{
	m_pOwner->GetEventManager()->Add_Listener("Static Collision", [this](const ArksEngine::Event& event)
		{
			EventHandler(event);
		}, 1);
}

void ArksEngineComponents::HealthComponent::EventHandler(const ArksEngine::Event& event)
{
	const ArksEngine::GameObject* pGameObject = nullptr;

	// Get the event arguments
	const auto& args = event.GetArgs();

	// Check if there's at least one argument
	if (!args.empty())
	{
		// Try to cast the first argument to GameObject*
		try
		{
			pGameObject = std::any_cast<ArksEngine::GameObject*>(args[0]);
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << "Bad Cast" << std::endl;
		}
	}

	if (pGameObject->GetTag() == "Enemy")
	{
		KillPlayer();
	}
}
