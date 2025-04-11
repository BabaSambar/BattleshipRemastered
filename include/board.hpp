#include <iostream>
#include <memory>
#include "tileMap.hpp"
#include "managers.hpp"
#include "stateManager.hpp"
#include "logger.hpp"

namespace BR {
	class Board {
	public:
		Board(int size, int tileNum, sf::Vector2i positions) 
			: m_size(size)
			, m_tileNum(tileNum)
			, m_position(positions)
			, m_tileMap(m_size, m_tileNum)
		{

		}

		// Draw textures here by scanning each tile state
		bool draw(sf::RenderWindow& window) {
			m_tileMap.draw(window);
		}

		void handleEvents(){
			// Check if any tiles are clicked, change state then

			// m_TileMap.UpdateTile(index, state);
		}

		void update(){
			// Update the textures of all tiles


			m_tileMap.update();
		}

		// Get board size
		int getBoardSize(){
			return m_size;
		}
		// Get tile size on the board
		int getTileSize(){
			return m_size / m_tileNum;
		}

	private:
		// Size of board
		int m_size;
		// Number of tiles per axis
		int m_tileNum;
		// Coordinate of board on window
		sf::Vector2i m_positions;
		// Private tilemap for storing states
		TileMap m_tileMap;

		// Shared texture manager per state
		TextureManager* m_textureManager;

		// Checks if all ships on board are destroyed / intact
		bool m_allShipsDestroyed;
		// Score of board. Each hit is 1 point, each sink is 1 point
		bool m_score;

	};
}
