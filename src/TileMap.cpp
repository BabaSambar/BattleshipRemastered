#include <TileMap.hpp>

namespace BR {
	void BR::TileMap::Load(int size, int tilenum = 10, sf::Vector2i Position = { 0, 0 }) {
		m_Tiles = std::vector<std::vector<Tile>>(size, std::vector<Tile>(size));
		// Set coordinates of all tiles use posX and posY
		int multiplier = size / tilenum;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				m_Tiles[i][j]._Positions.x = Position.x + (i * multiplier);
				m_Tiles[i][j]._Positions.y = Position.y + (j * multiplier);
			}
		}
		SetTiles(TileState::Unoccupied);  // Default tile state is unoccupied (water)
	}

	void BR::TileMap::SetTiles(TileState TileState) {
		for (auto line : m_Tiles) {
			for (auto tile : line) {
				tile._TileState = TileState;
			}
		}
	}

	void BR::TileMap::SetTileState(Tile Tile) {
		m_Tiles[Tile._Indices.x][Tile._Indices.y]._TileState = Tile._TileState;
	}

	BR::Tile& BR::TileMap::GetTile(sf::Vector2i tileIndex) {
		return m_Tiles[tileIndex.x][tileIndex.y];
	}

	BR::TileState BR::TileMap::GetTileState(sf::Vector2i index) {
		return m_Tiles[index.x][index.y]._TileState;
	}

	void BR::TileMap::AddShip(Ship& Ship) {
		m_Ships.push_back(Ship);
	}

	void BR::TileMap::ClearShips() {
		m_Ships.clear();
	}

	BR::Ship& BR::TileMap::GetShip(sf::Vector2i index) {
		// check which ship has tile
		for (Ship& ship : m_Ships) {
			if (std::find(ship._Coordinates.begin(), ship._Coordinates.end(), index) != ship._Coordinates.end()) {
				return ship;
			}
		}
		BR::Ship temp;
		return temp;
	}
}