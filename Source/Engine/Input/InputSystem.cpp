#include "InputSystem.h"

namespace kiko
{
	bool InputSystem::Initialize()
	{
		int numKeys;
		// get pointer to sdl keyboard states and number of keys
		const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);
		// resize of keyboard state vector using numKeys for size
		m_keyboardState.resize(numKeys);
		// copy the sdl key states to keyboard state
		std::copy(keyboardState, keyboardState + numKeys, m_keyboardState.begin());
		// set previous keyboard state to current keyboard state
		m_prevKeyboardState = m_keyboardState;
		return true;
	}

	void InputSystem::Shutdown()
	{

	}

	void InputSystem::Update()
	{
		// update sdl events
		SDL_Event event;
		SDL_PollEvent(&event);
		// save previous keyboard state
		m_prevKeyboardState = m_keyboardState;
		// get sdl keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		// copy sdl keyboard state to input system keyboard state
		std::copy(keyboardState, keyboardState + m_keyboardState.size(), m_keyboardState.begin());
	}
}