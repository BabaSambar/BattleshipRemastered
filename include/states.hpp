#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "managers.hpp"
#include "button.hpp"
#include "board.hpp"

namespace BR {
	class State {
	public:
		virtual void update(sf::RenderWindow& window) = 0;
		virtual void draw(sf::RenderWindow& window) = 0;
		virtual void handleEvents(sf::RenderWindow& window, sf::Event& event) = 0;
		virtual ~State() {}
	};

	class MainMenuState : public State {
		public:
			MainMenuState();
			void update(sf::RenderWindow& window) override;
			void draw(sf::RenderWindow& window) override;
			void handleEvents(sf::RenderWindow& window, sf::Event& event) override;
		private:
			Button m_button;
			bool m_goNext = false;
	};

	class GameOngoingState : public State {
		public:
			GameOngoingState();
			void update(sf::RenderWindow& window) override;
			void draw(sf::RenderWindow& window) override;
			void handleEvents(sf::RenderWindow& window, sf::Event& event) override;
		private:
			Board m_board;
			Button m_button;
	};

	// class GameOverState...

}