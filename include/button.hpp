#pragma once
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "managers.hpp"
#include "stateManager.hpp"

namespace BR {
	class Button {
	public:
		// Constructor
		Button(sf::Vector2f position, sf::Vector2f size, std::string displayText, sf::Color buttonColor, sf::Color hoverColor)
			: m_buttonColor(buttonColor), m_hoverColor(hoverColor), m_isClicked(false), m_isHovered(false) {
			m_shape.setSize(size);
			m_shape.setPosition(position);
			m_shape.setFillColor(m_buttonColor);
			
			// Load font, exit if font not found
			if (!m_fontManager->exists("OpenSans")) {
				m_fontManager->load("OpenSans", "res/fonts/OpenSans.ttf");
			}
			if (m_fontManager->exists("OpenSans")) m_font = m_fontManager->get("OpenSans");
			else return;

			m_text.setCharacterSize(26);
			m_text.setFillColor(sf::Color::Black);
			m_text.setFont(m_font);
			m_text.setString(displayText);
			centerText();
			handleTextOverflow();
			scaleTextSize();
		}
		// Change colors while drawing
		void draw(sf::RenderWindow& window) {
			if (m_isHovered) {
				m_shape.setFillColor(m_hoverColor);
			}
			else {
				m_shape.setFillColor(m_buttonColor);
			}
			window.draw(m_shape);
			window.draw(m_text);
		}
		// Change hover and click state
		void handleEvent(sf::Event& event, sf::RenderWindow& window) {
			if (event.type == sf::Event::MouseMoved) {
				sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
				sf::FloatRect bounds = m_shape.getGlobalBounds();
				m_isHovered = bounds.contains(mousePos);
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				if (m_isHovered) {
					m_isClicked = true;
				}
			}
		}
		// Check if button is clicked
		bool isClicked() {
			if (m_isClicked) {
				m_isClicked = false;
				return true;
			}
			return false;
		}

	// Helper functions and data members
	private:
		// Center the text within the button
		void centerText() {
			sf::FloatRect textBounds = m_text.getLocalBounds();
			sf::FloatRect buttonBounds = m_shape.getGlobalBounds();

			float textX = buttonBounds.left + (buttonBounds.width - textBounds.width) / 2 - textBounds.left;
			float textY = buttonBounds.top + (buttonBounds.height - textBounds.height) / 2 - textBounds.top;

			m_text.setPosition(textX, textY);
		}
		// If the text is wider than the button, truncate it and add ...
		void handleTextOverflow() {
			sf::FloatRect buttonBounds = m_shape.getGlobalBounds();
			sf::FloatRect textBounds = m_text.getLocalBounds();

			if (textBounds.width > buttonBounds.width) {
				std::string label = m_text.getString();
				float ellipsisWidth = m_text.getFont()->getGlyph('.', m_text.getCharacterSize(), false).advance * 3;
				while (label.size() >= 4 && textBounds.width + ellipsisWidth > buttonBounds.width) {
					for(int i=0; i<4; i++) label.pop_back();
					m_text.setString(label + "...");
					textBounds = m_text.getLocalBounds();
				}
			}
		}
		// Scale the text size based on the button's height
		void scaleTextSize() {
			sf::FloatRect buttonBounds = m_shape.getGlobalBounds();
			unsigned int textSize = static_cast<unsigned int>(buttonBounds.height * 0.5);
			textSize = std::clamp(textSize, 12u, 26u);
			m_text.setCharacterSize(textSize);
			centerText();
		}

		// Base shape of button
		sf::RectangleShape m_shape;
		// Text on the button
		sf::Text m_text;
		// Default color of button
		sf::Color m_buttonColor;
		// Color changed when button is clicked
		sf::Color m_hoverColor;
		bool m_isClicked;
		bool m_isHovered;
		// Font for current button
		sf::Font m_font;
	};
}
