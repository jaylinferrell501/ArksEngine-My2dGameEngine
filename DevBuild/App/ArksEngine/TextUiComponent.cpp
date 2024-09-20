#include "TextUiComponent.h"
#include "FontManager.h"

ArksEngineComponents::TextUiComponent::TextUiComponent(ArksEngine::Core* pRenderer, const char* path, int fontSize, const char* pText)
	:m_pText(pText)
{
	m_pFontManager = new ArksEngine::FontManager(pRenderer);

	m_pFontManager->LoadFont(path, fontSize);
}

void ArksEngineComponents::TextUiComponent::Update(double deltaTime)
{
	Component::Update(deltaTime);
}

void ArksEngineComponents::TextUiComponent::Render(float xOffset)
{
	m_pFontManager->RenderTextToScreen(m_pText, ArksEngine::FontManager::YELLOW, 100, 100);
}
