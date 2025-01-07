#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <StateManager.hpp>

namespace BR {
	class GameLoop {
	public:
		// Initialize game with starting state
		GameLoop(sf::Vector2i WindowSize, std::string GameTitle);
		// Start the game
		void Start();

	private:
		// Window for the game
		sf::RenderWindow m_Window;
		// Static state manager instance
		StateManager m_StateManager;
	};
}
