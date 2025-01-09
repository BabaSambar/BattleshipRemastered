#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Manager.hpp>
#include <GameMainMenuState.hpp>

namespace BR {
	class GameLoop {
	public:
		// Initialize game with starting state
		GameLoop(sf::Vector2i WindowSize, std::string GameTitle) : m_Window(sf::VideoMode(WindowSize.x, WindowSize.y), GameTitle) {
			m_StateManager.SetState(new MainMenuState(&m_StateManager));
			m_Window.setFramerateLimit(24);
		}
		// Start the game
		void Start() {
			while (m_Window.isOpen()) {
				sf::Event event;
				while (m_Window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						m_Window.close();
					}
					if (!m_StateManager.GetCurrentState()) continue;
					m_StateManager.GetCurrentState()->HandleEvents(m_Window, event);
				}

				if (!m_StateManager.GetCurrentState()) continue;
				m_StateManager.GetCurrentState()->Update(m_Window);

				if (!m_StateManager.GetCurrentState()) continue;
				m_StateManager.GetCurrentState()->Draw(m_Window);
			}
		}

	private:
		// Window for the game
		sf::RenderWindow m_Window;
		// Static state manager instance
		StateManager m_StateManager;
	};
}
