#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
#include <list>
#include <GL/gl.h>
#include <fstream>
#include <iostream>

#include "common.h"
#include "GameAssetManager.h"
#include "GameAsset.h"
#include "CubeAsset.h"

/**
 * GameWorld allows us to separate the management of the game world from the
 * nuts and bolts of game loop initialisation.  The GameWorld currently has
 * a very simplified scene graph consisiting of a single GameAssetManager.
 */
class GameWorld {
 public:
  /**
   * We thread the ApplicationMode through the GameWorld ss we want to read it
   * in from the user.  Threading the state through the various function calls
   * is preferable (in this case) to having some kind of global state.
   */
  GameWorld(ApplicationMode);
  std::shared_ptr<GameAssetManager> asset_manager;
  /**
   * Calling Draw() will draw the entire world.
   */
  void Draw();
 private:
  std::list<std::shared_ptr<GameAsset>> levelLayout;

};
#endif // GAMEWORLD_H hey
