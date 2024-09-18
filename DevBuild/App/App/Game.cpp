#include "Game.h"
#include "../ArksEngine/SceneManager.h"
#include "Scenes/TestArea.h"

void Game::InitializeApp(const char* name, const char* assetsFileName, int screenWidth, int screenHeight)
{
	ArksEngine_Initialize(name, assetsFileName, screenWidth, screenHeight); // Initialize The engine

	LoadScene(Test); // Loads out TestScene
}

void Game::Update(double deltaTime)
{
	GetSceneManager()->UpdateCurrentScene(deltaTime);
}

void Game::DisplayOutput()
{
	if (!GetQuit())
		GetSceneManager()->RenderCurrentScene();
}

void Game::LoadScene(SceneName scene)
{
	switch (scene)
	{
	case Test:
		GetSceneManager()->ChangeScene(new TestArea{ this });
		break;
	}
}
