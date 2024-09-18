#include "TestArea.h"

TestArea::TestArea(Game* pOwner)
	:Scene(pOwner)
{
}

void TestArea::Enter()
{
	Scene::Enter();
}

void TestArea::Exit()
{
	Scene::Exit();
}
