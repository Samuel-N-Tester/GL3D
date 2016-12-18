#include "GameWorld.h"
#include "GameAsset.h"

GameWorld::GameWorld(ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {

	std::vector<int> worldLoader;
	std::ifstream worldFile;

	worldFile.open("./worlds/world1.txt");

	int mapWidth = 0;
	int mapDepth = 0;
	int playerSpawnX = 0;
	int playerSpawnZ = 0;
	int playerCount = 0;

	worldFile >> mapWidth;
	worldFile >> mapDepth;

	// Find the player, if there is more then one it uses the
	// one closest to the bottom right (in reading order).
	for (int countZ = 0; countZ < mapDepth; countZ++) {

		for (int countX = 0; countX < mapWidth; countX++) {

			int placeValue;
			worldFile >> placeValue;
			worldLoader.push_back(placeValue);

			if (placeValue == 1) {
				playerSpawnZ = countZ;
				playerSpawnX = countX;
				playerCount++;
			}
		}
	}

	// Report if there are multiple cameras.
	if (playerCount > 1) {
		std::cout << "WARNING: multiple cameras detected, amount:   "
				<< playerCount << std::endl;
	}

	// Read position of cubes and place them relative to the player.
	for (int countZ = 0; countZ < mapDepth; countZ++) {

		for (int countX = 0; countX < mapWidth; countX++) {

			int currentPlace = worldLoader[(countZ * mapDepth) + countX];



			if (currentPlace == 0 || currentPlace == 1) {
				// Do nothing, its empty space or a player.

			} else if (currentPlace == 2) {

				// Make a cube in this location
				auto cube = std::make_shared<CubeAsset>(countX - playerSpawnX, -2, countZ - playerSpawnZ);
				cube->rotateY(45);
				levelLayout.push_back(cube);

			} else {

				// Unknown asset type default as empty space and print error.
				std::cout << "Unknown asset type:   " << currentPlace
						<< std::endl;
			}
		}
	}

	// Draw all objects on the levelLayout.
	for (auto levelObject : levelLayout) {
		asset_manager->AddAsset(levelObject);
	}
}

void GameWorld::Draw() {
	asset_manager->Draw();
}
