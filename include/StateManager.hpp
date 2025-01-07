#include <iostream>
#include <stack>
#include <States.hpp>

namespace BR {
	class StateManager {
	public:
		// Private constructor for static classes
		StateManager() {}
		StateManager(const StateManager&) = delete;
		StateManager& operator=(const StateManager&) = delete;
		// Push state to stack
		void AddState(State* state) {
			m_States.push(state);
		}
		// Pop state from stack
		void RemoveState() {
			if (!m_States.empty()) {
				m_States.pop();
			}
		}
		// Get current state on top of stack
		State* GetCurrentState() {
			return m_States.top();
		}

	private:
		// Stack of states
		std::stack<State*> m_States;
	};
}