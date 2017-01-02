/*
 * Camera.h
 *
 *  Created on: 16 Dec 2016
 *      Author: stester
 */

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_


#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <array>
#include <cmath>

#include <memory>
#include <iostream>

class Camera {
public:
	Camera();
	virtual ~Camera();
	glm::mat4 getViewMatrix();

	void translate(double, double, double);

	void rotateX(double);
	void rotateY(double);

private:
	double yaw;
	glm::mat4 viewTranslate;
	glm::mat4 viewRotateY;
	glm::mat4 viewRotateX;
};

#endif // SRC_CAMERA_H_
