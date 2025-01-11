#include <GameOngoingState.hpp>

namespace BR{
	GameOngoingState::GameOngoingState(StateManager* _StateManager): 
		m_Board(500, 10, {10, 10}, &m_TextureManager),
		m_Button({ 200, 200 }, { 200, 50 }, "New state!", sf::Color::White, sf::Color::Yellow, m_FontManager)
	{
		m_StateManager = _StateManager;
		m_TextureManager.Load("water", "res/Textures/water.png");
		m_TextureManager.Load("ship", "res/Textures/ship.png");
	}
	// Update main menu logic
	void GameOngoingState::Update(sf::RenderWindow& window) {
	}
	// Draw game UI
	void GameOngoingState::Draw(sf::RenderWindow& window) {
		window.clear();
		m_Button.Draw(window);
		m_Board.Draw(window);
		window.display();
	}
	// Handle state events
	void GameOngoingState::HandleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			// Switch to GameOverState
			// StateManager::getInstance().changeState(new GameOverState());
		}
		m_Button.HandleEvent(event, window);
	}
}
