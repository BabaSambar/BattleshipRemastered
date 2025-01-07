#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Manager.hpp>

namespace BR {
	class Button {
	public:
		// Constructor
		Button(sf::Vector2f Position, sf::Vector2f Size, std::string Title, sf::Color ButtonColor, sf::Color HoverColor, FontManager& FontManager)
			: m_ButtonColor(ButtonColor), m_HoverColor(HoverColor), m_isClicked(false), m_isHovered(false), m_FontManager(FontManager) {
			m_Shape.setSize(Size);
			m_Shape.setPosition(Position);
			m_Shape.setFillColor(m_ButtonColor);

			// Load font, exit if font not found
			if (!m_FontManager.Exists("OpenSans")) {
				m_FontManager.Load("OpenSans", "res/fonts/OpenSans.ttf");
			}
			if (m_FontManager.Exists("OpenSans")) m_Font = m_FontManager.Get("OpenSans");
			else return;

			m_Text.setCharacterSize(26);
			m_Text.setColor(sf::Color::Black);
			m_Text.setFont(m_Font);
			m_Text.setString(Title);
			CenterText();
			HandleTextOverflow();
			ScaleTextSize();
		}
		// Change colors while drawing
		void Draw(sf::RenderWindow& window) {
			if (m_isHovered) {
				m_Shape.setFillColor(m_HoverColor);
			}
			else {
				m_Shape.setFillColor(m_ButtonColor);
			}
			window.draw(m_Shape);
			window.draw(m_Text);
		}
		// Change hover and click state
		void HandleEvent(sf::Event& event, sf::RenderWindow& window) {
			if (event.type == sf::Event::MouseMoved) {
				sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
				sf::FloatRect bounds = m_Shape.getGlobalBounds();
				m_isHovered = bounds.contains(mousePos);
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				if (m_isHovered) {
					m_isClicked = true;
				}
			}
		}
		// Check if button is clicked
		bool IsClicked() {
			if (m_isClicked) {
				m_isClicked = false;
				return true;
			}
			return false;
		}

	// Helper functions and data members
	private:
		// Center the text within the button
		void CenterText() {
			sf::FloatRect textBounds = m_Text.getLocalBounds();
			sf::FloatRect buttonBounds = m_Shape.getGlobalBounds();

			float textX = buttonBounds.left + (buttonBounds.width - textBounds.width) / 2 - textBounds.left;
			float textY = buttonBounds.top + (buttonBounds.height - textBounds.height) / 2 - textBounds.top;

			m_Text.setPosition(textX, textY);
		}
		// If the text is wider than the button, truncate it and add ...
		void HandleTextOverflow() {
			sf::FloatRect buttonBounds = m_Shape.getGlobalBounds();
			sf::FloatRect textBounds = m_Text.getLocalBounds();

			if (textBounds.width > buttonBounds.width) {
				std::string label = m_Text.getString();
				float ellipsisWidth = m_Text.getFont()->getGlyph('.', m_Text.getCharacterSize(), false).advance * 3;
				while (label.size() >= 4 && textBounds.width + ellipsisWidth > buttonBounds.width) {
					for(int i=0; i<4; i++) label.pop_back();
					m_Text.setString(label + "...");
					textBounds = m_Text.getLocalBounds();
				}
			}
		}
		// Scale the text size based on the button's height
		void ScaleTextSize() {
			sf::FloatRect buttonBounds = m_Shape.getGlobalBounds();
			unsigned int textSize = static_cast<unsigned int>(buttonBounds.height * 0.5);
			textSize = std::clamp(textSize, 12u, 26u);
			m_Text.setCharacterSize(textSize);
			CenterText();
		}

		// Base shape of button
		sf::RectangleShape m_Shape;
		// Text on the button
		sf::Text m_Text;
		// Default color of button
		sf::Color m_ButtonColor;
		// Color changed when button is clicked
		sf::Color m_HoverColor;
		bool m_isClicked;
		bool m_isHovered;
		// Font for current button
		sf::Font m_Font;
		// State shared Font Manager
		FontManager m_FontManager;
	};
}
