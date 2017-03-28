/*
 * Camera.cc
 *
 *  Created on: 16 Dec 2016
 *      Author: stester
 */

#include "Camera.h"

Camera::Camera() {
	// TODO Auto-generated constructor stub

}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

glm::mat4 Camera::getViewMatrix() {
	return viewRotateX * viewRotateY * viewTranslate;
}

void Camera::translate(double x, double y, double z) {

	glm::mat4 translate;

	if (z != 0) {
		translate[3][0] -= viewRotateY[2][0]*z;
		translate[3][1] += y;
		translate[3][2] += viewRotateY[0][0]*z;
	}

	if (x != 0) {
			translate[3][0] += viewRotateY[0][0]*x;
			translate[3][1] += 0;
			translate[3][2] += viewRotateY[2][0]*x;
	}

	viewTranslate *= translate;
}

void Camera::rotateX(double degree) {

	degree = degree / 600;
	glm::mat4 rotate = glm::rotate(glm::mat4(), glm::mediump_float(degree), glm::vec3(1, 0, 0));

	viewRotateX *= rotate;
}

void Camera::rotateY(double degree) {

	degree = degree / 600;
	glm::mat4 rotate = glm::rotate(glm::mat4(), glm::mediump_float(degree), glm::vec3(0, 1, 0));

	viewRotateY *= rotate;


}// hey
