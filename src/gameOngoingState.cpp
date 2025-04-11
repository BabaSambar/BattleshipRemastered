#include "states.hpp"

namespace BR{
	GameOngoingState::GameOngoingState(): 
		m_board(500, 10, {10, 10}, m_textureManager),
		m_button({ 200, 200 }, { 200, 50 }, "New state!", sf::Color::White, sf::Color::Yellow)
	{
		m_textureManager->load("water", "res/Textures/water.png");
		m_textureManager->load("ship", "res/Textures/ship.png");
	}
	// Update main menu logic
	void GameOngoingState::update(sf::RenderWindow& window) {
	}
	// Draw game UI
	void GameOngoingState::draw(sf::RenderWindow& window) {
		window.clear();
		m_button.draw(window);
		m_board.draw(window);
		window.display();
	}
	// Handle state events
	void GameOngoingState::handleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			// Switch to GameOverState
			// StateManager::getInstance().changeState(new GameOverState());
		}
		m_button.handleEvent(event, window);
	}
}
