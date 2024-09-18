#pragma once
#include "ArksEngine.h"

class Game : public ArksEngine::Core
{
public:

	enum SceneName
	{
		Test,
	};

	Game() = default;
	~Game() = default;

	void InitializeApp(const char* name, const char* assetsFileName, int screenWidth, int screenHeight);

	void Update(double deltaTime) override;

	void DisplayOutput() override;

	void LoadScene(SceneName scene);
};

