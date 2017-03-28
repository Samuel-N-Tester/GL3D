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

	glm::mat4 xTranslate;

	xTranslate[1][1] = cos(degree);
	xTranslate[1][2] = sin(degree);
	xTranslate[2][1] = -sin(degree);
	xTranslate[2][2] = cos(degree);

	viewRotateX *= xTranslate;
}

void Camera::rotateY(double degree) {

	degree = degree / 600;

	glm::mat4 yTranslate;

	yTranslate[0][0] = cos(degree);
	yTranslate[0][2] = -sin(degree);
	yTranslate[2][0] = sin(degree);
	yTranslate[2][2] = cos(degree);

	viewRotateY *= yTranslate;


}
