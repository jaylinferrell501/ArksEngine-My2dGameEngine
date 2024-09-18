#pragma once
#include "unordered_map"

namespace ArksEngine
{
	class Core;

	class Input
	{
		ArksEngine::Core* m_pOwner; //  This is a Ptr to the Core
		std::unordered_map<int, bool> mInputMap; // This is A HashMap for the keys
		bool mQuit; // A boolean for Quitting
	public:
		
		enum KeyCode
		{
			KeyCode_W,
			KeyCode_S,
			KeyCode_D,
			KeyCode_A,
			KeyCode_R,
			KeyCode_G,
			KeyCode_B,
			KeyCode_E,
			KeyCode_L,
			KeyCode_C,
			KeyCode_Space,
			KeyCode_Esc,

			Last
		};

	private:
		void ResetInput(); // We need to clear previous input
		void AddKey(int key, bool pressed); // Lets us add more inputs
	public:
		Input(ArksEngine::Core* pOwner); // This is a constructor for our Input
		~Input() = default; // A default De-constructor
		void ProcessInput(); // Preprocess our input
		bool GetKeyPressed(KeyCode keyCode); // Checks to see if A key is pressed
		bool GetTwoKeysPressed(KeyCode keyCode, KeyCode keycode2); // Checks to see if 2 keys are Pressed
		
	};
}


