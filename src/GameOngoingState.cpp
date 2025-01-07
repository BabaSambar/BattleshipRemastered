#include <States.hpp>

namespace BR {
	void GameOngoingState::Update(sf::RenderWindow& window) {
		// Update main menu logic
	}
	void GameOngoingState::Draw(sf::RenderWindow& window) {
		window.clear();
		// Draw game UI
		window.display();
	}
	void GameOngoingState::HandleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			// Switch to GameOverState
			// StateManager::getInstance().changeState(new GameOverState());
		}
	}
}