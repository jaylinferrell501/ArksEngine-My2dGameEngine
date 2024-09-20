#include "TestArea.h"

#include "../../ArksEngine/FontManager.h"
#include "../../ArksEngine/TextUiComponent.h"

TestArea::TestArea(Game* pOwner)
	:Scene(pOwner)
{
}

void TestArea::Enter()
{
	ArksEngine::GameObject& helloText(GetEntityManager()->AddGameObject());
	helloText.AddComponent<ArksEngineComponents::TransformComponent>();
	helloText.AddComponent<ArksEngineComponents::TextUiComponent>(GetOwner(), "Assets/Roboto-Black.ttf", 24, "Hello World");

	helloText.GetComponent<ArksEngineComponents::TransformComponent>().SetPosition(32 * 40, 32 * 23);
	helloText.GetComponent<ArksEngineComponents::TransformComponent>().SetScale(0, 0);



	//GetOwner()->GetFontManager()->LoadFont("Assets/Roboto-Black.ttf", 24);
	//
	//ArksEngine::Texture* hello = new ArksEngine::Texture(GetOwner());
	//
	//// Set the texture from the rendered text
	//hello->SetTexture(GetOwner()->GetFontManager()->RenderText("Hello, SDL_TTF!", ArksEngine::FontManager::BLACK, GetOwner()->GetRenderer()->GetSDLRenderer()));
	//
	//hello->RenderTexture({0, 0}, {10, 10},{20, 20});
}

void TestArea::Exit()
{
	Scene::Exit();
}
