﻿#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Game.hpp>

int main()
{
	BR::GameLoop Game({ 800, 600 }, "Battleship Remastered");
	Game.Start();
	return 0;
}