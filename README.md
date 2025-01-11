# Battleship Remastered
An old project I wanted to complete.

The game features:
- Singleplayer battleship game
- Customizable difficulty in singleplayer
- Multiplayer support for playing with a friend (using sockets)
Some features I plan to add in the future are:
- Custom boards
- Ship captain classes and abilities based on them

For compilation and execution:
1. On Linux (Only tested on Ubuntu 20.1+):
	- Install SFML using `sudo apt install lsfml--dev`
	- Clone this repository
	- Create a build folder inside the source directory
	- run cmake command `cmake -S ..` inside the build folder
	- run make command `make` inside build folder
	- The executable is created. Run the command for starting the game `./BattleshipRemastered`
2. On Windows:
	- Check the releases tab, download, extract and run directly without any issues :D

Let me know if you have any issues / suggestions by opening a discussion or emailing me. 