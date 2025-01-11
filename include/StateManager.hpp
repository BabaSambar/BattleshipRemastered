#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <State.hpp>

namespace BR{
	class StateManager {
	public:
		StateManager() {}
		// Set new state
		void SetState(State* _State){
			m_CurrentState = _State;
		}
		// Get current state on top of stack
		State* GetCurrentState() {
			return m_CurrentState;
		}
	private:
		// Store only the active state
		State* m_CurrentState;
	};
}