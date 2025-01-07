#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include <Button.hpp>
#include <Manager.hpp>

namespace BR {
	class State {
	public:
		virtual void Update(sf::RenderWindow& window) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;
		virtual void HandleEvents(sf::RenderWindow& window, sf::Event& event) = 0;
		virtual ~State() {}
	
		TextureManager m_TextureManager;
		FontManager m_FontManager;
	};

	class MainMenuState : public State {
	public:
		MainMenuState();
		void Update(sf::RenderWindow& window) override;
		void Draw(sf::RenderWindow& window) override;
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override;
	private:
		Button m_button;
		bool m_GoNext = false;

	};
	class GameOngoingState : public State {
	public:
		GameOngoingState();
		void Update(sf::RenderWindow& window) override;
		void Draw(sf::RenderWindow& window) override;
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override;
	private:

	};
	class GameOverState : public State {
	public:
		GameOverState();
		void Update(sf::RenderWindow& window) override;
		void Draw(sf::RenderWindow& window) override;
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override;
	private:

	};
}