#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "common.h"
#include "GameAsset.h"
#include "Camera.h"

/**
 * GameAssetManager is a container for GameAssets.  It also provides utility
 * functions to to create a simple OpenGL program that can be used to draw a
 * simple GameAsset.
 */
class GameAssetManager {
public:
	explicit GameAssetManager(ApplicationMode); // constructor
	virtual ~GameAssetManager();
	GameAssetManager(GameAssetManager const&); // copy constructor
	GameAssetManager(GameAssetManager const&&); // move constructor
	void moveCamera(double, double, double);
	void rotateCamera(char, double);
	void operator=(GameAssetManager const&); // assignment
	void AddAsset(std::shared_ptr<GameAsset>);
	void Draw();

private:
	Camera camera;
	GLuint CreateGLProgram(std::string &, std::string &);
	GLuint CreateGLESShader(GLenum, std::string &);
	// As this is private and we're writing to the GPU, we will use raw pointers.
	std::pair<GLchar *, GLint> ReadShader(std::string &);

	// The internal scene graph is a simple list.
	std::vector<std::shared_ptr<GameAsset>> draw_list;
	GLuint program_token;
};

#endif // GAMEASSETMANAGER_H
