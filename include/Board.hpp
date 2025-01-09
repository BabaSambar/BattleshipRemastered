#include <iostream>
#include <memory>
#include <TileMap.hpp>
#include <Manager.hpp>

namespace BR {
	class Board {
	public:
		Board(int size, int tilenum, sf::Vector2i positions, TextureManager* _textureManager) : m_Size(size), m_TileNum(tilenum), m_Positions(positions) 
		{
			m_TextureManager = _textureManager;
			m_TileMap.Load(size, tilenum, positions);
		}

		// Draw textures here by scanning each tile state
		bool Draw(sf::RenderWindow& window) {
			// verify textures
			if (!(m_TextureManager->Exists("water") && m_TextureManager->Exists("ship") && m_TextureManager->Exists("ship_destroyed") && m_TextureManager->Exists("ship_destroying")))
			{
				std::cout << "Cannot open texture while drawing board.\n";
				return false;
			}
			/*
			sf::Texture waterTex = m_TextureManager->Get("water");
			sf::Texture shipTex = m_TextureManager->Get("ship");
			sf::Texture shipDestroyedTex = m_TextureManager->Get("ship_destroyed");
			sf::Texture shipDestroyingTex = m_TextureManager->Get("ship_destroying");

			std::cout << m_TextureManager->Exists("water") << "\n";

			// apply textures
			sf::RectangleShape rect(sf::Vector2f(m_Size / m_TileNum, m_Size / m_TileNum));
			for (int i = 0; i < m_TileNum; i++) {
				for (int j = 0; j < m_TileNum; j++) {
					Tile Tile = m_TileMap.GetTile({ i, j });
					rect.setPosition(Tile._Positions.x, Tile._Positions.y);
					
					if (Tile._TileState == TileState::Occupied) {
						// Check what is the ship status on this.
						Ship ship = m_TileMap.GetShip({ i, j });
						for (int i = 0; i < ship._Coordinates.size(); i++) {
							if (ship._States[i] == ShipState::Visible) {
								rect.setTexture(&shipTex);
							}
							else if (ship._States[i] == ShipState::Damaged) {
								rect.setTexture(&shipDestroyingTex);
							}
							else if (ship._States[i] == ShipState::Destroyed) {
								rect.setTexture(&shipDestroyedTex);
							}
						}
					}
					else if (Tile._TileState == TileState::Unknown) {
						rect.setTexture(&waterTex);
					}
					else if (Tile._TileState == TileState::Unoccupied) {
						rect.setTexture(&waterTex);
					}
					else {
						std::cout << "No standard tile state.\n";
					}
					window.draw(rect);
				}
			}
			*/
			return true;
		}
		// Get an entire tile, ask for state in it later
		Tile& GetTile(sf::Vector2i tileIndex){
			return m_TileMap.GetTile(tileIndex);
		}
		// Set an entire tile, put state in it beforehand
		void SetTile(sf::Vector2i tileIndex, Tile tile){
			m_TileMap.SetTileState(tile);
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
	};
}
