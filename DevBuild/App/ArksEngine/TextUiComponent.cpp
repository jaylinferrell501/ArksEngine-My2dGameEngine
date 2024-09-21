#include "TextUiComponent.h"
#include "FontManager.h"
#include "GameObject.h"
#include "Components/TransformComponent.h"

ArksEngineComponents::TextUiComponent::TextUiComponent(ArksEngine::Core* pRenderer, const char* path, int fontSize, const char* pText)
	:m_pTransformRef(nullptr)
	,m_text(pText)
	,m_pFontSize(fontSize)
{
	m_pFontManager = new ArksEngine::FontManager(pRenderer);

	m_pFontManager->LoadFont(path, fontSize);
}

void ArksEngineComponents::TextUiComponent::Init()
{
	// Let's Get a ref to our transform
	m_pTransformRef = &mGameObj->GetComponent<TransformComponent>();
}

void ArksEngineComponents::TextUiComponent::Update(double deltaTime)
{
	Component::Update(deltaTime);
}

void ArksEngineComponents::TextUiComponent::Render(float xOffset)
{
	// Render the text using m_text.c_str() to convert std::string back to const char*
	m_pFontManager->RenderTextToScreen(m_text.c_str(), ArksEngine::FontManager::BLACK,
		static_cast<int>(m_pTransformRef->GetPosition().m_x),
		static_cast<int>(m_pTransformRef->GetPosition().m_y),
		m_pFontSize, m_pFontSize);
}
