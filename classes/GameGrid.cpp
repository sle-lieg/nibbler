#include "GameGrid.hpp"

// GameGrid::GameGrid(int width, int height)
// {
// 	for (int y = TILE_SIZE; y < height; y += TILE_SIZE) {
// 		for (int x = 0; x < width; x += TILE_SIZE) {
// 			_coords.emplace(_coords.begin(), std::make_pair(x, y));
// 		}
// 	}
// }

GameGrid::GameGrid()
{
	for (int y = 0; y < g_gameHeight; y += TILE_SIZE) {
		for (int x = 0; x < g_gameWidth; x += TILE_SIZE) {
			_coords.emplace(_coords.begin(), std::make_pair(x, y));
		}
	}
	// for (int y = TILE_SIZE; y < g_gameHeight; y += TILE_SIZE) {
	// 	for (int x = 0; x < g_gameWidth; x += TILE_SIZE) {
	// 		_coords.emplace(_coords.begin(), std::make_pair(x, y));
	// 	}
	// }
}

GameGrid::~GameGrid(void) {}

