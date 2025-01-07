#include <States.hpp>

namespace BR {
	MainMenuState::MainMenuState() :
		m_button({ 200, 200 }, { 200, 50 }, "Click Me!", sf::Color::White, sf::Color::Yellow, m_FontManager) {

	}
	void MainMenuState::Update(sf::RenderWindow& window) {
		// Update main menu logic
	}
	void MainMenuState::Draw(sf::RenderWindow& window) {
		window.clear(sf::Color::Cyan);
		m_button.Draw(window);
		window.display();
	}
	void MainMenuState::HandleEvents(sf::RenderWindow& window, sf::Event& event) {
		if (m_GoNext) {
			std::cout << "GO NEXT\n";
			//Switch to GameOngoingState
			//StateManager::RemoveState();
			//StateManager::GetInstance().AddState(new GameOngoingState());
		}
		m_button.HandleEvent(event, window);

		if (m_button.IsClicked()) {
			m_GoNext = true;
		}
	}
}