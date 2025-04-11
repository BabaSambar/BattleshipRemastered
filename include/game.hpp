#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "states.hpp"
#include "stateManager.hpp"
#include "logger.hpp"

namespace BR {
	class GameLoop {
	public:
		// Initialize game with starting state
		GameLoop(sf::Vector2i windowSize, std::string gameTitle) : m_window(sf::VideoMode(windowSize.x, windowSize.y), gameTitle) {
			m_stateManager->setState(new MainMenuState(m_stateManager));
			m_window.setFramerateLimit(24);  // TODO: Change to delta time interpolation
		}
		// Start the game
		void start() {
			// Log game start
			while (m_window.isOpen()) {
				sf::Event event;
				while (m_window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						m_window.close();
					}
					if (!m_stateManager->getCurrentState()) continue;
					m_stateManager->getCurrentState()->handleEvents(m_window, event);
				}

				if (!m_stateManager->getCurrentState()) continue;
				m_stateManager->getCurrentState()->update(m_window);

				if (!m_stateManager->getCurrentState()) continue;
				m_stateManager->getCurrentState()->draw(m_window);
			}
			// Log game end
		}

	private:
		// Window for the game
		sf::RenderWindow m_window;
	};
}
