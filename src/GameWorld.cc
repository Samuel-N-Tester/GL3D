#include "GameWorld.h"

GameWorld::GameWorld(ApplicationMode mode) :
		asset_manager(std::make_shared<GameAssetManager>(mode)) {

	std::string world = "world2";

	std::vector<int> layerList;



	std::ifstream worldInfoFile;
	std::ifstream layerPositionFile;

	worldInfoFile.open("./worlds/" + world + "/worldInfo.txt");
	if (!worldInfoFile.is_open()) {
		std::cout << "worldInfoFile  Didn't open" << std::endl;
	}

	int layerAmount = 0;

	int mapWidth = 0;
	int mapDepth = 0;

	int playerSpawnX = 0;
	int playerSpawnY = 0;
	int playerSpawnZ = 0;

	worldInfoFile >> playerSpawnX;
	worldInfoFile >> playerSpawnY;
	worldInfoFile >> playerSpawnZ;

	worldInfoFile >> mapWidth;
	worldInfoFile >> mapDepth;

	worldInfoFile >> layerAmount;

	// Read in a list of all the layers
	for (int count = 0; count < layerAmount; count++) {
		int currentLayer;
		worldInfoFile >> currentLayer;
		layerList.push_back(currentLayer);
	}
	worldInfoFile.close();

	for (auto hight : layerList) {

		std::vector<int> layerObjectPositions;

		std::vector<double> layerObjectRotationsX;
		std::vector<double> layerObjectRotationsY;
		std::vector<double> layerObjectRotationsZ;

		std::string layer = "./worlds/" + world + "/layer" + std::to_string(hight) + ".txt";
		std::cout << layer << std::endl;
		layerPositionFile.open(layer);
		if (!layerPositionFile.is_open()) {
			std::cout << "Layer  " << hight << "  Didn't open" << std::endl;
		}

		// Find the player, if there is more then one it uses the
		// one closest to the bottom right (in reading order).
		for (int countZ = 0; countZ < mapDepth; countZ++) {

			for (int countX = 0; countX < mapWidth; countX++) {

				int placeValue;
				layerPositionFile >> placeValue;
				layerObjectPositions.push_back(placeValue);
				std::cout << placeValue << "   ";

			}
			std::cout << std::endl;
		}

		// Add rotations for X axis
		for (int countZ = 0; countZ < mapDepth; countZ++) {

			for (int countX = 0; countX < mapWidth; countX++) {

				int rotationValueX;
				layerPositionFile >> rotationValueX;
				layerObjectRotationsX.push_back(rotationValueX);

			}
		}

		// Add rotations for Y axis
		for (int countZ = 0; countZ < mapDepth; countZ++) {

			for (int countX = 0; countX < mapWidth; countX++) {

				int rotationValueY;
				layerPositionFile >> rotationValueY;
				layerObjectRotationsY.push_back(rotationValueY);

			}
		}

		// Add rotations for Z axis
		for (int countZ = 0; countZ < mapDepth; countZ++) {

			for (int countX = 0; countX < mapWidth; countX++) {

				int rotationValueZ;
				layerPositionFile >> rotationValueZ;
				layerObjectRotationsZ.push_back(rotationValueZ);

			}
		}

		layerPositionFile.close();

		// Read position of cubes and place them relative to the player.
		for (int countZ = 0; countZ < mapDepth; countZ++) {
			for (int countX = 0; countX < mapWidth; countX++) {

				int currentPlace = layerObjectPositions[(countZ * mapWidth)+ countX];

				if (currentPlace == 0 || currentPlace == 1) {
					// Do nothing, its empty space or a player.

				} else if (currentPlace == 2) {

					auto cube = std::make_shared<CubeAsset>(countX - playerSpawnX, hight - playerSpawnY,countZ - playerSpawnZ);

					// Rotate the cube to the correct start orientation
					cube->rotateX(
							layerObjectRotationsX[(countZ * mapWidth) + countX]);
					cube->rotateY(
							layerObjectRotationsY[(countZ * mapWidth) + countX]);
					cube->rotateZ(
							layerObjectRotationsZ[(countZ * mapWidth) + countX]);

					levelLayout.push_back(cube);
				} else {

					// Unknown asset type default as empty space and print error.
					std::cout << "Unknown asset type:   " << currentPlace
							<< "    " << (countZ * mapDepth) + countX
							<< std::endl;
				}
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
