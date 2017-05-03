#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <GL/gl.h>
#include <BoundingBox.h>

#include <iostream>

class GameAsset {
public:
	virtual void Draw(GLuint) = 0;
	glm::mat4 getModelMatrix();

	void translate(double, double, double);

	void rotateX(double);
	void rotateY(double);
	void rotateZ(double);

protected:
	glm::mat4 model;
	BoundingBox boundingBox;

};

#endif // GAMEASSET_H
