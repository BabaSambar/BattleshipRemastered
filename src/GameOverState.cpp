#include <States.hpp>

namespace BR {
	void GameOverState::Update(sf::RenderWindow& window) {
		// Update main menu logic
	}
	void GameOverState::Draw(sf::RenderWindow& window) {
		window.clear();
		// Draw game over UI
		window.display();
	}
	void GameOverState::HandleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			// Switch to MainMenuState
			// StateManager::getInstance().changeState(new MainMenuState());
		}
	}
}