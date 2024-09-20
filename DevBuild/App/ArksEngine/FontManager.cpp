#include "FontManager.h"
#include <SDL.h>
#include <SDL_ttf.h>

#include "Core.h"
#include "Renderer.h"
#include "Utillities/Debug_Log.h"


// Define static color constants
const SDL_Color ArksEngine::FontManager::WHITE = { 255, 255, 255, 255 };
const SDL_Color ArksEngine::FontManager::BLACK = { 0, 0, 0, 255 };
const SDL_Color ArksEngine::FontManager::RED = { 255, 0, 0, 255 };
const SDL_Color ArksEngine::FontManager::GREEN = { 0, 255, 0, 255 };
const SDL_Color ArksEngine::FontManager::BLUE = { 0, 0, 255, 255 };
const SDL_Color ArksEngine::FontManager::YELLOW = { 255, 255, 0, 255 };

ArksEngine::FontManager::FontManager(ArksEngine::Core* pOwner)
	:m_pOwner(pOwner)
{
}

bool ArksEngine::FontManager::LoadFont(const char* path, int fontSize)
{
	m_pFont = TTF_OpenFont(path, fontSize);
	if (m_pFont == nullptr)
		return false;

	return true;
}

SDL_Texture* ArksEngine::FontManager::RenderText(const char* text, const SDL_Color& color)
{
	if (m_pFont == nullptr)
	{
		m_pOwner->GetDebug_Log()->Error("Font is not loaded!");
		return nullptr;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(m_pFont, text, color);
	if (surface == nullptr) 
	{
		m_pOwner->GetDebug_Log()->Error("Error creating surface!");
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_pOwner->GetRenderer()->GetSDLRenderer(), surface);
	SDL_FreeSurface(surface);

	if (texture == nullptr) 
	{
		m_pOwner->GetDebug_Log()->Error("Error creating texture!");
		return nullptr;
	}

	return texture;
}

void ArksEngine::FontManager::RenderTextToScreen(const char* text, const SDL_Color& color,
	int x, int y)
{
	// Render the text to a texture
	SDL_Texture* texture = RenderText(text, color);
	if (!texture)
	{
		m_pOwner->GetDebug_Log()->Error("Unable to render text to texture!");
		return;
	}

	// Get texture dimensions
	int textWidth = x;
	int textHeight = y;
	SDL_QueryTexture(texture, nullptr, nullptr, &textWidth, &textHeight);

	// Define destination rectangle for rendering
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = textWidth;
	destRect.h = textHeight;

	// Copy texture to the renderer
	SDL_RenderCopy(m_pOwner->GetRenderer()->GetSDLRenderer(), texture, nullptr, &destRect);

	// Clean up the texture
	SDL_DestroyTexture(texture);

}

void ArksEngine::FontManager::CloseFont()
{
	if (m_pFont != nullptr) 
	{
		TTF_CloseFont(m_pFont);
		m_pFont = nullptr;
	}
}
