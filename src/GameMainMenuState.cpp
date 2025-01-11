#include <Manager.hpp>
#include <Button.hpp>
#include <GameMainMenuState.hpp>
#include <GameOngoingState.hpp>

namespace BR{
	MainMenuState::MainMenuState(StateManager* _StateManager) :
		m_Button({ 200, 200 }, { 200, 50 }, "Click Me!", sf::Color::White, sf::Color::Yellow, m_FontManager) {
		m_StateManager = _StateManager;
		// m_TextureManager.Load("water", "res/Textures/water.png");
	}
	void MainMenuState::Update(sf::RenderWindow& window) {
		// Update main menu logic
	}
	void MainMenuState::Draw(sf::RenderWindow& window) {
		window.clear(sf::Color::Cyan);
		m_Button.Draw(window);
		window.display();
	}
	void MainMenuState::HandleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (m_GoNext) {
			// std::cout << "GO NEXT\n";
			m_GoNext = false;
			// Switch to GameOngoingState
			std::cout << "NEXT STATE\n";
			m_StateManager->SetState(new GameOngoingState(m_StateManager));
		}
		m_Button.HandleEvent(event, window);

		if (m_Button.IsClicked()) {
			m_GoNext = true;
		}
	}
}
