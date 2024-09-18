#pragma once

namespace ArksEngine
{
	class GameObjectManager;
	class Core;
}

namespace ArksEngineBuilders
{
	class GameObjectBuilder
	{
		ArksEngine::Core* m_pOwner;
		ArksEngine::GameObjectManager* m_pEntityManager;
	public:
		GameObjectBuilder(ArksEngine::Core* pOwner, ArksEngine::GameObjectManager* pManager);
		~GameObjectBuilder() = default;

		void CreateGameObject(const char* pXml_File) const;
	};
}


