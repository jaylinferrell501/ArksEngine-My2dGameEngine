#include "TestArea.h"

#include "../../ArksEngine/FontManager.h"
#include "../../ArksEngine/TextUiComponent.h"

TestArea::TestArea(Game* pOwner)
	:Scene(pOwner)
{
}

void TestArea::Enter()
{
	//ArksEngine::GameObject& backGround(GetEntityManager()->AddGameObject());
	//backGround.AddComponent<ArksEngineComponents::SpriteComponent>(GetOwner(), "StartBackground.png");
	//backGround.GetComponent<ArksEngineComponents::TransformComponent>().SetPosition(32 * 0, 32 * 0);
	//backGround.GetComponent<ArksEngineComponents::TransformComponent>().SetScale(1024, 768);

	LoadEntity("Background.xml");

	//ArksEngine::GameObject& startButton(GetEntityManager()->AddGameObject());
	//startButton.AddComponent<ArksEngineComponents::SpriteComponent>(GetOwner(), "StartButton.png");
	//startButton.GetComponent<ArksEngineComponents::SpriteComponent>().SetTextureColor(0,255,0);
	//startButton.GetComponent<ArksEngineComponents::TransformComponent>().SetPosition(32 * 3, 32 * 22);
	//startButton.GetComponent<ArksEngineComponents::TransformComponent>().SetScale(812, 64);

	LoadEntity("StartButton.xml");

	//ArksEngine::GameObject& startButtonText(GetEntityManager()->AddGameObject());
	//startButtonText.AddComponent<ArksEngineComponents::TextUiComponent>(GetOwner(), "Assets/ComicNeue-Bold.ttf", 30, "PRESS  START");
	//startButtonText.GetComponent<ArksEngineComponents::TransformComponent>().SetPosition(32 * 13, 32 * 22.5);
	//startButtonText.GetComponent<ArksEngineComponents::TransformComponent>().SetScale(812, 64);

	LoadEntity("StartButtonText.xml");

}

void TestArea::Exit()
{
	Scene::Exit();
}
