#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace BR {
	// Enumerator for tile states
	enum TileState {
		Unknown,
		Unoccupied,
		Occupied
	};
	// Enumerator for a single tile
	struct Tile {
		// Indices for tilemap
		sf::Vector2i _Indices;
		// Coordinates on tilemap
		sf::Vector2i _Positions;
		// State of a tile inside a tilemap
		TileState _TileState;
	};
	// Enumerator for ship states
	enum ShipState {
		Visible,
		Damaged,
		Destroyed
	};
	// Struct for entire ships
	struct Ship {
		// Vector of indices of all ship parts
		std::vector<sf::Vector2i> _Coordinates;
		// Vector of states of all ship parts
		std::vector<ShipState> _States;
		// Boolean if ship is destroyed
		bool Destroyed;
	};

	// Base tilemap class
	class TileMap{
	public:
		TileMap() : m_Size(0), m_TileNum(0) {};
		// Initialize a tilemap with given size. TILENUM and positions have default arguments
		void Load(int size, int tilenum = 10, sf::Vector2i Position = { 0, 0 }) {
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
		// Set all tiles to given state
		void SetTiles(TileState TileState) {
			for (auto line : m_Tiles) {
				for (auto tile : line) {
					tile._TileState = TileState;
				}
			}
		}		
		// Get a reference of a given tile index
		Tile& GetTile(sf::Vector2i tileIndex) {
			return m_Tiles[tileIndex.x][tileIndex.y];
		}
		// Set tile data to given tile information
		void SetTileState(Tile Tile) {
			m_Tiles[Tile._Indices.x][Tile._Indices.y]._TileState = Tile._TileState;
		}
		// Get tile state of given tilemap index
		TileState GetTileState(sf::Vector2i index) {
			return m_Tiles[index.x][index.y]._TileState;
		}
		// Add a new ship into tilemap ship vector. Assumes all ships are visible
		void AddShip(Ship& Ship) {
			m_Ships.push_back(Ship);
		}
		// Get ship on current index
		Ship& GetShip(sf::Vector2i index) {
			// check which ship has tile
			for (Ship& ship : m_Ships) {
				if (std::find(ship._Coordinates.begin(), ship._Coordinates.end(), index) != ship._Coordinates.end()) {
					return ship;
				}
			}
			return m_Ships[0];
		}
		// Clear all ships from the tilemap
		void ClearShips() {
			m_Ships.clear();
		}

	private:
		// Size of tilemap in pixels and number of tiles on the tilemap
		const int m_Size, m_TileNum;
		// Position of first tile in the tilemap in pixel space
		sf::Vector2i m_Position;
		// Private vector of all tiles
		std::vector<std::vector<Tile>> m_Tiles;
		// Private vector of ships on the tilemap
		std::vector<Ship> m_Ships;
	};
}
