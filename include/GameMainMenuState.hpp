#pragma once
#include <Manager.hpp>
#include <Button.hpp>

namespace BR{
	class MainMenuState : public State {
	public:
		MainMenuState(StateManager* _StateManager);
		void Update(sf::RenderWindow& window) override;
		void Draw(sf::RenderWindow& window) override;
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override;
	private:
		Button m_Button;
		bool m_GoNext = false;
		StateManager* m_StateManager;
	};
}
