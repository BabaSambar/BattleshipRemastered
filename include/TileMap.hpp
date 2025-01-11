#pragma once
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <Manager.hpp>

namespace BR {
	enum class TileState {
		Water,
		ShipHidden,
		ShipVisible,
		ShipDestroying,
		ShipDestroyed
	};
	enum class ShipPart {
		End,
		Middle
	}

	class Tile {
	public:
		Tile(sf::Vector2f _Position, TextureManager* _TextureManager, TileState _TileState=TileState::Water):
			m_Position(_Position),
			m_TileState(_TileState),
			m_TextureManager(_TextureManager),
			m_ShipPart(ShipPart::Middle)
		{
			m_Rect.setFillColor(sf::Color::White);
			m_Rect.setPosition(_Positions);
			SetTexture();
		}
		// Set new state of tile
		void SetTileState(TileState _TileState) {
			m_TileState = _TileState;
		}
		// Get tile state
		TileState& GetState(){
			return m_TileState;
		}
		// Set the texture of rectangle shape according to tile state
		bool SetTexture(sf::Angle _Rotation = 0){
			// Verify textures
			if (!(m_TextureManager->Exists("water")
				&& m_TextureManager->Exists("ship_middle_intact")
				&& m_TextureManager->Exists("ship_end_intact")
				&& m_TextureManager->Exists("ship_middle_destroying")
				&& m_TextureManager->Exists("ship_end_destroying")
				&& m_TextureManager->Exists("ship_middle_destroyed")
				&& m_TextureManager->Exists("ship_end_destroyed"))) 
			{
				return false;
			}
			// Random rotation for water
			std::random_devide rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dist(0, 3);
			// Add ability to add directional, connected textures
			switch(m_TileState){
			case TileState::Water:
				m_Texture = m_TextureManager->Get("water");
				m_Texture.setRotation(90 * dist(gen));
				break;
			case TileState::ShipHidden:
				m_Texture = m_TextureManager->Get("water");
				m_Texture.setRotation(90 * dist(gen));
				break;
			case TileState::ShipVisible:
				if(m_ShipPart == ShipPart::Middle){
					m_TextureManager->Get("ship_middle_intact");
				}
				else if(m_ShipPart == ShipPart::End){
					m_TextureManager->Get("ship_end_intact");
				}
				break;
			case TileState::ShipDestroying:
				if(m_ShipPart == ShipPart::Middle){
					m_TextureManager->Get("ship_middle_destroying");
				}
				else if(m_ShipPart == ShipPart::End){
					m_TextureManager->Get("ship_end_destroying");
				}
				break;
			case TileState::ShipDestroyed:
				if(m_ShipPart == ShipPart::Middle){
					m_TextureManager->Get("ship_middle_destroyed");
				}
				else if(m_ShipPart == ShipPart::End){
					m_TextureManager->Get("ship_end_destroyed");
				}
				break;
			default:
				std::cout << "Invalid tile state." std::endl;
				return false;
			}
			m_Texture.setRotation(_Rotation);
			return true;
		}
		// Draw the rectangle
		void Draw(sf::RenderWindow& _Window){
			_Window.draw(m_Rect);
		}
	private:
		// Coordinate position on tilemap
		sf::Vector2f m_Position;
		// Tile state for current tile
		TileState m_TileState;
		// Ship part *if* the tile is a ship
		ShipPart m_ShipPart;
		// Rectangle shape for applying texture
		sf::RectangleShape m_Rect;
		// Pointer to state texture manager
		TextureManager* m_TextureManager;
		// Texture for current tile
		sf::Texture* m_Texture;
	};

	class TileMap {
	public:
		TileMap(sf::Vector2i _Size, int _TileNum, TextureManager* _TextureManager):
			m_TileMap(_TileNum, std::vector<Tile>(_TileMap)),
			m_Size(_Size),
			m_TileNum(_TileNum),
			m_TextureManager(_TextureManager)
		{
			// Set states and positions
			for(int i=0; i<m_TileNum, i++){
				for(int j=0; j<m_TileNum; j++){
					sf::Vector2f _Position = {(m_Size / m_TileNum) * j, (m_Size / m_TileNum) * i};
					Tile _Tile(_Position, m_TextureManager);
					m_TileMap[j][i] = _Tile;
				}
			}
		}
		// Update a single tile state
		bool UpdateTile(sf::Vector2i _Index, TileState _TileState){
			if(_Index.x < 0 || _Index.x >= m_TileNum || _Index.y < 0 || _Index.y > m_TileNum) return false;
			m_TileMap[_Index.y][_Index.x].SetTileState(_TileState);
			return true;

			// Add state by checking neighbouring tile states
		}
		// Update all tiles as per their states
		void Update(){
			for(int i=0; i<m_TileNum; i++){
				for(int j=0; j<m_TileNum; j++){
					m_TileMap[j][i].SetTexture();
				}
			}

			// Rotate the textures according to neighbouring tiles
		}
		// Draw the tiles on window
		void Draw(sf::RenderWindow& _Window){
			for(int i=0; i<m_TileNum; i++){
				for(int j=0; j<m_TileNum; j++){
					m_TileMap[j][i].Draw(_Window);
				}
			}
		}
	private:
		// 2D tilemap
		std::vector<std::vector<Tile>> m_TileMap;
		// Coordinate size of tilemap
		sf::Vector2i m_Size;
		// Number of tiles per row / column
		int m_TileNum;
		// State level texture manager
		TextureManager* m_TextureManager;
	};
}
