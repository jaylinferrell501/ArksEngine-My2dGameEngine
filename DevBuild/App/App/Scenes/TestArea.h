#pragma once
#include "../ArksEngine.h"
#include "../Game.h"

class TestArea : public ArksEngine::Scene
{
public:
	TestArea(Game* pOwner);
	~TestArea() = default;


	/**
	 * \brief Enters our scene
	 */
	void Enter() override;


	/**
	 * \brief Exits our scene
	 */
	void Exit() override;
};

