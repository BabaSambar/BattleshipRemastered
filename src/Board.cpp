#include <Board.hpp>

BR::Board::Board(int size, int tilenum, sf::Vector2i positions, std::shared_ptr<TextureManager> textureManager) : m_Size(size), m_TileNum(tilenum), m_Positions(positions) {
	m_TextureManager = textureManager;
	m_TileMap.Load(size, tilenum, positions);
}

bool BR::Board::Draw(sf::RenderWindow& window) {
	// verify textures
	if (!(m_TextureManager->Exists("water") && m_TextureManager->Exists("ship") && m_TextureManager->Exists("ship_destroyed") && m_TextureManager->Exists("ship_destroying")))
	{
		std::cout << "Cannot open texture while drawing board.\n";
		return false;
	}
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
	return true;
}

BR::Tile& BR::Board::GetTile(sf::Vector2i tileIndex){
	return m_TileMap.GetTile(tileIndex);
}

void BR::Board::SetTile(sf::Vector2i tileIndex, Tile tile){
	m_TileMap.SetTileState(tile);
}

int BR::Board::GetBoardSize(){
	return m_Size;
}

int BR::Board::GetTileSize(){
	return m_Size / m_TileNum;
}

