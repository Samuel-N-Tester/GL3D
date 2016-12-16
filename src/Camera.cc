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

glm::mat4 Camera::getViewMatrix(){
	return view;
}

void Camera::moveX(double speedPerSecond){
	view[3][0] = view[3][0] + (speedPerSecond/60);
}

void Camera::moveY(double speedPerSecond){
	view[3][0] = view[3][0] + (speedPerSecond/60);
}

void Camera::moveZ(double speedPerSecond){
	view[3][0] = view[3][0] + (speedPerSecond/60);
}

void Camera::rotateX(double degreePerSecond){

	degreePerSecond = degreePerSecond/60;

	glm::mat4 xTranslate;

	xTranslate[1][1] = cos(degreePerSecond);
	xTranslate[1][2] = sin(degreePerSecond);
	xTranslate[2][1] = -sin(degreePerSecond);
	xTranslate[2][2] = cos(degreePerSecond);

	view *= xTranslate;
}

void Camera::rotateY(double degreePerSecond){

	degreePerSecond = degreePerSecond/60;

	glm::mat4 yTranslate;

	yTranslate[0][0] = cos(degreePerSecond);
	yTranslate[0][2] = -sin(degreePerSecond);
	yTranslate[2][0] = sin(degreePerSecond);
	yTranslate[2][2] = cos(degreePerSecond);

	view *= yTranslate;

}
