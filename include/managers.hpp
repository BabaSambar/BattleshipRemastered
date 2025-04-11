#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unordered_map>

namespace BR {
	// Generic class which handles texture, sound, audio and fonts
	template<typename resource>
	class Manager {
	public:
		// Constructor
		Manager() = default;
		// Load a resource
		bool load(std::string resourceName, std::string resourcePath) {
			if (exists(resourceName)) return true;
			Resource data;
			if (!data.loadFromFile(resourcePath)) return false;
			m_resourceMap[resourceName] = data;
			return false;
		}
		// Get a reference to a resource. Assumed that resource exists
		resource& get(std::string resourceName) {
			return m_resourceMap.at(resourceName);
		}
		// Check if a resource exists
		bool exists(std::string resourceName) {
			if (m_resourceMap.find(resourceName) == m_resourceMap.end()) return false;
			return true;
		}
		// Remove a resource
		bool remove(std::string resourceName) {
			if (m_resourceMap.find(resourceName) != m_resourceMap.end()) m_resourceMap.erase(resourceName);
			return true;
		}
		// Clear all resources
		bool clear() {
			m_resourceMap.clear();
			return true;
		}
		int size(){
			return m_resourceMap.size();
		}
	protected:
		// Private resource map containing all resources of a type
		std::unordered_map<std::string, resource> m_resourceMap = {};
	};

	class TextureManager : public Manager<sf::Texture> {};
	class FontManager: public Manager<sf::Font> {};
	class SoundManager : public Manager<sf::Sound> {};

	// Pointer to global texture manager
	extern TextureManager *m_textureManager;
	// Pointer to global font manager
	extern FontManager *m_fontManager;
	// Pointer to global sound manager
	extern SoundManager *_soundManager;
}