#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "states.hpp"

namespace BR{
	class StateManager {
	public:
		StateManager() {}
		// Set new state
		void setState(State* _state){
			m_currentState = _state;
		}
		// Get current state on top of stack
		State* getCurrentState() {
			return m_currentState;
		}
	private:
		// Store only the active state
		State* m_currentState;
	};

	extern StateManager *m_stateManager;
}