#include <iostream>
#include <memory>
#include <TileMap.hpp>
#include <Manager.hpp>
#include <StateManager.hpp>
#include <Logger.hpp>

namespace BR {
	class Board {
	public:
		Board(int Size, int _TileNum, sf::Vector2i _Positions, TextureManager* _TextureManager) 
			: m_Size(_Size)
			, m_TileNum(_TileNum)
			, m_Positions(_Positions)
			, m_TextureManager(_TextureManager)
			, m_TileMap(m_Size, m_TileNum, m_TextureManager)
		{

		}

		// Draw textures here by scanning each tile state
		bool Draw(sf::RenderWindow& _Window) {
			m_TileMap.Draw(_Window);
		}

		void HandleEvents(){
			// Check if any tiles are clicked, change state then

			// m_TileMap.UpdateTile(index, state);
		}

		void Update(){
			// Update the textures of all tiles


			m_TileMap.Update();
		}

		// Get board size
		int GetBoardSize(){
			return m_Size;
		}
		// Get tile size on the board
		int GetTileSize(){
			return m_Size / m_TileNum;
		}

	private:
		// Size of board
		int m_Size;
		// Number of tiles per axis
		int m_TileNum;
		// Coordinate of board on window
		sf::Vector2i m_Positions;
		// Private tilemap for storing states
		TileMap m_TileMap;

		// Shared texture manager per state
		TextureManager* m_TextureManager;

		// Checks if all ships on board are destroyed / intact
		bool m_AllShipsDestroyed;
		// Score of board. Each hit is 1 point, each sink is 1 point
		bool m_Score;

	};
}
