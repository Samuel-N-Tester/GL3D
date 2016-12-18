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
	return view;
}

void Camera::translate(double x, double y, double z) {

	glm::mat4 translate;

	translate[3][0] = x;
	translate[3][1] = y;
	translate[3][2] = z;

	view *= translate;
}

void Camera::rotateX(double degreePerSecond) {

	degreePerSecond = degreePerSecond / 60;

	glm::mat4 xTranslate;

	xTranslate[1][1] = cos(degreePerSecond);
	xTranslate[1][2] = sin(degreePerSecond);
	xTranslate[2][1] = -sin(degreePerSecond);
	xTranslate[2][2] = cos(degreePerSecond);

	view *= xTranslate;
}

void Camera::rotateY(double degreePerSecond) {

	degreePerSecond = degreePerSecond / 60;

	glm::mat4 yTranslate;

	yTranslate[0][0] = cos(degreePerSecond);
	yTranslate[0][2] = -sin(degreePerSecond);
	yTranslate[2][0] = sin(degreePerSecond);
	yTranslate[2][2] = cos(degreePerSecond);

	view *= yTranslate;

}
