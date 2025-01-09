#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
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
}