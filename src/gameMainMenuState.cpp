#include "states.hpp"

namespace BR{
	MainMenuState::MainMenuState() :
		m_button({ 200, 200 }, { 200, 50 }, "Click Me!", sf::Color::White, sf::Color::Yellow) {
		;
		// m_TextureManager.Load("water", "res/Textures/water.png");
	}
	void MainMenuState::update(sf::RenderWindow& window) {
		// Update main menu logic
	}
	void MainMenuState::draw(sf::RenderWindow& window) {
		window.clear(sf::Color::Cyan);
		m_button.draw(window);
		window.display();
	}
	void MainMenuState::handleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (m_goNext) {
			// std::cout << "GO NEXT\n";
			m_goNext = false;
			// Switch to GameOngoingState
			std::cout << "NEXT STATE\n";
			m_stateManager->setState(new GameOngoingState());
		}
		m_button.handleEvent(event, window);

		if (m_button.isClicked()) {
			m_goNext = true;
		}
	}
}
