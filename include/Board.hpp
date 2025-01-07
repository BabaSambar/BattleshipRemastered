#include <iostream>
#include <memory>

#include <TileMap.hpp>
#include <Manager.hpp>
/// <summary>
/// Directions to use in GameLoop:
///	- Initialize a board object(s)
///	- Set all necessary parameters
/// - According to turns, check for mouse interrupts / computer moves in GameLoop class itself
/// - Call the set tile method of the object
/// - Call the draw method each frame
/// </summary>
namespace BR {
	class Board {
	public:
		Board(int size, int tilenum, sf::Vector2i positions, std::shared_ptr<TextureManager> textureManager);
		
		// Draw textures here by scanning each tile state
		bool Draw(sf::RenderWindow& window);
		// Get an entire tile, ask for state in it later
		Tile& GetTile(sf::Vector2i tileIndex);
		// Set an entire tile, put state in it beforehand
		void SetTile(sf::Vector2i tileIndex, Tile tile);

		// Get board size
		int GetBoardSize();
		// Get tile size on the board
		int GetTileSize();

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
		std::shared_ptr<TextureManager> m_TextureManager;
	};
}
