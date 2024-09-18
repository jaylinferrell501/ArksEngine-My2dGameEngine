#pragma once
#include <string>

#include "Component.h"


struct SDL_Rect;


namespace ArksEngine
{
	class Renderer;
}

namespace ArksEngineComponents
{
	class TransformComponent;

	class ColliderComponent : public Component
	{
		SDL_Rect* m_pCollider;
		std::string mTag;
		ArksEngine::Renderer* m_pRenderer;

		int mWidth = 0;
		int mHeight = 0;
		int mXOffset = 0;
		int mYOffset = 0;

		ArksEngineComponents::TransformComponent* m_pTransform;


	public:
		ColliderComponent(ArksEngine::Renderer* pRenderer);

		[[nodiscard]] SDL_Rect* GetCollider() const { return m_pCollider; }

		void Init() override;
		void Update(double deltaTime) override;
		void Render(float xOffset) override;

		void SetWidth(int w) { mWidth = w; }
		void SetHeight(int h) { mHeight = h; }
		void SetXOffset(int x) { mXOffset = x; }
		void SetYOffset(int y) { mYOffset = y; }

		void SetScale(float x, float y);
	};
}

