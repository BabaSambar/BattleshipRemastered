#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unordered_map>

namespace BR {
	// Generic class which handles texture, sound, audio and fonts
	template<typename Resource>
	class Manager {
	public:
		// Constructor
		Manager() = default;
		// Load a resource
		bool Load(std::string ResourceName, std::string ResourcePath) {
			if (Exists(ResourceName)) return true;
			Resource Data;
			if (!Data.loadFromFile(ResourcePath)) return false;
			m_ResourceMap[ResourceName] = Data;
			return false;
		}
		// Get a reference to a resource. Assumed that resource exists
		Resource& Get(std::string ResourceName) {
			return m_ResourceMap.at(ResourceName);
		}
		// Check if a resource exists
		bool Exists(std::string ResourceName) {
			if (m_ResourceMap.find(ResourceName) == m_ResourceMap.end()) return false;
			return true;
		}
		// Remove a resource
		bool Remove(std::string ResourceName) {
			if (m_ResourceMap.find(ResourceName) != m_ResourceMap.end()) m_ResourceMap.erase(ResourceName);
			return true;
		}
		// Clear all resources
		bool Clear() {
			m_ResourceMap.clear();
			return true;
		}
	protected:
		// Private resource map containing all resources of a type
		std::unordered_map<std::string, Resource> m_ResourceMap;
	};

	class TextureManager : public Manager<sf::Texture> {};
	class FontManager: public Manager<sf::Font> {};
	class SoundManager : public Manager<sf::Sound> {};
}