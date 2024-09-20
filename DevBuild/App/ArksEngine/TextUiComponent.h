#pragma once
#include "Components/Component.h"

namespace ArksEngine
{
	class Core;
	class Texture;
	class FontManager;
}

namespace ArksEngineComponents
{
	class TextUiComponent : public Component
	{
		ArksEngine::FontManager* m_pFontManager = nullptr;
		const char* m_pText = nullptr;

	public:
		TextUiComponent(ArksEngine::Core* pRenderer, const char* path, int fontSize, const char* pText);

		void Update(double deltaTime) override;

		void Render(float xOffset) override;
	};
}


