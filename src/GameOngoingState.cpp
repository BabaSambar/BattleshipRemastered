#include <Manager.hpp>
#include <Button.hpp>
#include <Board.hpp>

namespace BR{
	class GameOngoingState : public State {
	public:
		GameOngoingState(StateManager* _StateManager): 
			m_Board(500, 10, {10, 10}, &m_TextureManager),
			m_Button({ 200, 200 }, { 200, 50 }, "New state!", sf::Color::White, sf::Color::Yellow, m_FontManager)
		{
			m_StateManager = _StateManager;
			m_TextureManager.Load("water", "res/Textures/water.png");
		}
		// Update main menu logic
		void Update(sf::RenderWindow& window) override {
		}
		// Draw game UI
		void Draw(sf::RenderWindow& window) override {
			window.clear();
			m_Button.Draw(window);
			m_Board.Draw(window);
			window.display();
		}
		// Handle state events
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				// Switch to GameOverState
				// StateManager::getInstance().changeState(new GameOverState());
			}
			m_Button.HandleEvent(event, window);
		}

	private:
		Board m_Board;
		// Keep a pointer to global state manager class for calling next states
		StateManager* m_StateManager;
		Button m_Button;
	};
}
