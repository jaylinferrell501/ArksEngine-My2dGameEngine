#pragma once
#include <string>

#include "Components/Component.h"

namespace ArksEngine
{
	class Core;
	class Texture;
	class FontManager;
}

namespace ArksEngineComponents
{
	class TransformComponent;

	class TextUiComponent : public Component
	{
		ArksEngine::FontManager* m_pFontManager = nullptr;
		ArksEngineComponents::TransformComponent* m_pTransformRef = nullptr;
		std::string m_text;  // Store the text as a std::string to manage memory safely
		int m_pFontSize = 0;

	public:
		TextUiComponent(ArksEngine::Core* pRenderer, const char* path, int fontSize, const char* pText);

		void Init() override;

		void Update(double deltaTime) override;

		void Render(float xOffset) override;
	};
}


