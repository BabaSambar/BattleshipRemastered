#include <Manager.hpp>
#include <Button.hpp>
#include <../src/GameOngoingState.cpp>

namespace BR{
	class MainMenuState : public State {
	public:
		MainMenuState(StateManager* _StateManager) :
			m_Button({ 200, 200 }, { 200, 50 }, "Click Me!", sf::Color::White, sf::Color::Yellow, m_FontManager) {
			m_StateManager = _StateManager;
		}
		void Update(sf::RenderWindow& window) override {
			// Update main menu logic
		}
		void Draw(sf::RenderWindow& window) override {
			window.clear(sf::Color::Cyan);
			m_Button.Draw(window);
			window.display();
		}
		void HandleEvents(sf::RenderWindow& window, sf::Event& event) override {
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
		~MainMenuState(){
			std::cout << "Destroyed Main Menu State\n";
		}
	private:
		Button m_Button;
		bool m_GoNext = false;
		StateManager* m_StateManager;
	};
}
