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
		void Load(int size, int tilenum, sf::Vector2i positions);

		// Set all tiles to given state
		void SetTiles(TileState tileState);
		// Get a reference of a given tile index
		Tile& GetTile(sf::Vector2i tileIndex);
		// Set tile data to given tile information
		void SetTileState(Tile tile);
		// Get tile state of given tilemap index
		TileState GetTileState(sf::Vector2i index);

		// Add a new ship into tilemap ship vector. Assumes all ships are visible
		void AddShip(Ship& ship);
		// Clear all ships from the tilemap
		void ClearShips();
		// Get ship on current index
		Ship& GetShip(sf::Vector2i index);

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
