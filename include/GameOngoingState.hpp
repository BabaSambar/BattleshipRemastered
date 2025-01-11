#pragma once
#include <Manager.hpp>
#include <Button.hpp>
#include <Board.hpp>

namespace BR{
	class GameOngoingState : public State {
	public:
		GameOngoingState(StateManager* _StateManager);
		void Update(sf::RenderWindow& window) override;
		void Draw(sf::RenderWindow& window) override;
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override;
	private:
		Board m_Board;
		StateManager* m_StateManager;
		Button m_Button;
	};
}
