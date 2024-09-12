#pragma once
#include "Component.h"

namespace ArksEngine
{
	class Core;
}

// Very simple Health component
namespace ArksEngineComponents
{
	class HealthComponent : public Component
	{
		bool mIsAlive = true;
		ArksEngine::Core* m_pOwner;

	public:
		HealthComponent(ArksEngine::Core* pOwner);

		void Init() override;

		void EventHandler(const ArksEngine::Event& event) override;

		void KillPlayer() { mIsAlive = false; }

		bool GetIsAlive() const { return  mIsAlive; }
	};

}
