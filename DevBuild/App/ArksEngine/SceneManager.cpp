#include "SceneManager.h"
#include "Interfaces/Scene.h"

ArksEngine::SceneManager::SceneManager(ArksEngine::Core* pOwner)
	:m_pOwner(pOwner)
	, m_pCurrentScene(nullptr)
	, m_pNextScene(nullptr)
{
}

ArksEngine::SceneManager::~SceneManager()
{
	// exit the current state.
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Exit();
	}

	// delete the current state
	delete m_pCurrentScene;
}

void ArksEngine::SceneManager::UpdateCurrentScene(double deltaTime)
{
	// Perform actual state change here
	if (m_pNextScene != nullptr)
	{
		ChangeScene(m_pNextScene);
		m_pNextScene = nullptr;
	}

	// If My current state is not null call update.
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Update(deltaTime);
	}
}

void ArksEngine::SceneManager::RenderCurrentScene() const
{
	// If My current state is not null call Render.
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Render();
	}
}

void ArksEngine::SceneManager::ChangeScene(Scene* pNewScene)
{
	// exit the current state.
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Exit();
	}
	// delete the old state
	delete m_pCurrentScene;
	// load the new state.
	m_pCurrentScene = pNewScene;

	// enter the new state.
	pNewScene->Enter();
}
