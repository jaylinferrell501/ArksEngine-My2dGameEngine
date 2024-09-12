#include "Input.h"

#include <iostream>
#include <SDL.h>

#include "Core.h"
#include "Utillities/Debug_Log.h"

ArksEngine::Input::Input(ArksEngine::Core* pOwner)
	:m_pOwner(pOwner)
	,mQuit(false)
{
	/// <summary>
	/// Loops through our enum and Adds the key
	/// </summary>
	/// <param name="pOwner"></param>
	for (int key = 0; key != Last; ++key)
	{
		AddKey(key, false);
	}

	m_pOwner->GetDebug_Log()->Log("Input Created");
}

/**
 * \brief Resets Input values back to false
 */
void ArksEngine::Input::ResetInput()
{
	for (int key = 0; key < mInputMap.size(); key++)
	{
		mInputMap[key] = false;
	}
}

/**
 * \brief Adds input to our Input un_orderer map
 * \param key KeyCode
 * \param pressed Boolean to check if key was pressed
 */
void ArksEngine::Input::AddKey(int key, bool pressed)
{
	mInputMap.emplace(key, pressed);
}

/**
 * \brief Processes the given input using SDL_PollEvent
 */
void ArksEngine::Input::ProcessInput()
{
	const Uint8* keyboard_state = SDL_GetKeyboardState(nullptr);

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:

			// IF THE WINDOW EVENT WAS CLOSE WINDOW	
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				mInputMap[KeyCode_Esc] = true;
			}
			break;

		case SDL_KEYDOWN:

			if (keyboard_state[SDL_SCANCODE_R])
				mInputMap[KeyCode_R] = true;
			if (keyboard_state[SDL_SCANCODE_E])
				mInputMap[KeyCode_E] = true;
			if (keyboard_state[SDL_SCANCODE_B])
				mInputMap[KeyCode_B] = true;
			if (keyboard_state[SDL_SCANCODE_G])
				mInputMap[KeyCode_G]= true;
			if (keyboard_state[SDL_SCANCODE_L])
				mInputMap[KeyCode_L] = true;
			if (keyboard_state[SDL_SCANCODE_C])
				mInputMap[KeyCode_C] = true;
			if (keyboard_state[SDL_SCANCODE_ESCAPE])
				mInputMap[KeyCode_Esc] = true;

			if(keyboard_state[SDL_SCANCODE_A])
				mInputMap[KeyCode_A] = true;
			if (keyboard_state[SDL_SCANCODE_W])
				mInputMap[KeyCode_W] = true;
			if (keyboard_state[SDL_SCANCODE_D])
				mInputMap[KeyCode_D] = true;
			if (keyboard_state[SDL_SCANCODE_S])
				mInputMap[KeyCode_S] = true;

			break;
		case SDL_KEYUP:

			if (event.key.keysym.sym == SDLK_r)
				mInputMap[KeyCode_R] = false;
			if (event.key.keysym.sym == SDLK_e)
				mInputMap[KeyCode_E] = false;
			if (event.key.keysym.sym == SDLK_b)
				mInputMap[KeyCode_B] = false;
			if (event.key.keysym.sym == SDLK_g)
				mInputMap[KeyCode_G] = false;
			if (event.key.keysym.sym == SDLK_l)
				mInputMap[KeyCode_L] = false;
			if (event.key.keysym.sym == SDLK_c)
				mInputMap[KeyCode_C] = false;
			if (event.key.keysym.sym == SDLK_ESCAPE)
				mInputMap[KeyCode_Esc] = false;

			if (event.key.keysym.sym == SDLK_a)
				mInputMap[KeyCode_A] = false;
			if (event.key.keysym.sym == SDLK_w)
				mInputMap[KeyCode_W] = false;
			if (event.key.keysym.sym == SDLK_d)
				mInputMap[KeyCode_D] = false;
			if (event.key.keysym.sym == SDLK_s)
				mInputMap[KeyCode_S] = false;
			break;

		}

	}
}

bool ArksEngine::Input::GetKeyPressed(KeyCode keyCode)
{
	if (mInputMap[keyCode] == true)
		return true;

	return false;
}

bool ArksEngine::Input::GetTwoKeysPressed(KeyCode keyCode, KeyCode keycode2)
{
	if (mInputMap[keyCode] == true && mInputMap[keycode2 == true])
		return true;
	return false;
}
