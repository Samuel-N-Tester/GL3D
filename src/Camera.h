/*
 * Camera.h
 *
 *  Created on: 16 Dec 2016
 *      Author: stester
 */

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <array>
#include <cmath>

#include <memory>
#include <iostream>
#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

class Camera {
public:
	Camera();
	virtual ~Camera();
	glm::mat4 getViewMatrix();

	void moveX(double);
	void moveY(double);
	void moveZ(double);

	void rotateX(double);
	void rotateY(double);
	void rotateZ(double);


private:
	glm::mat4 view;
};

#endif /* SRC_CAMERA_H_ */
