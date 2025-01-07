#include <iostream>
#include <Game.hpp>

namespace BR {
	GameLoop::GameLoop(sf::Vector2i WindowSize, std::string GameTitle) : m_Window(sf::VideoMode(WindowSize.x, WindowSize.y), GameTitle) {
		m_StateManager.AddState(new MainMenuState());
	}

	void GameLoop::Start() {
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
}
