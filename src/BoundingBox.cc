/*
 * BoundingBox.cc
 *
 *  Created on: 21 Feb 2017
 *      Author: stester
 */

#include "BoundingBox.h"

BoundingBox::BoundingBox() {
	// TODO Auto-generated constructor stub

}

BoundingBox::~BoundingBox() {
	// TODO Auto-generated destructor stub
}

glm::vec3 BoundingBox::GetSizeVec() {
	return halfX + halfY + halfZ;
}

double BoundingBox::GetRadius(){
	return radius;
}

bool BoundingBox::CollidesWithBoxBox(glm::vec3 position, glm::vec3 otherPosition, glm::vec3 otherHalfVecs) {

	bool collided = true;

	glm::vec3 halfVecs = GetSizeVec();

	// tests to see if it can draw a dividing line on any axis
	for (int i = 0; i < 3; i++) {
		if (position[i] - halfVecs[i] > otherPosition[i] + otherHalfVecs[0]) {
			collided = false;
		}
		if (position[i] + halfVecs[i] < otherPosition[i] - otherHalfVecs[0]) {
			collided = false;
		}
	}

	std::cout << "COLLISON - box box" << std::endl;

	return collided;
}

bool BoundingBox::CollidesWithBoxCircle(glm::vec3 position, glm::vec3 otherPosition, double otherRadius) {

	bool collided = false;

	glm::vec3 halfVecs = GetSizeVec();
	glm::vec3 closestPoint;
	glm::vec3 XYZDistance;
	double distance = 0;


	// find the closest point on the cube to the sphere
	for (int i = 0; i < 3; i++) {

		if (position[i] - halfVecs[i] > otherRadius) {
			closestPoint[i] = position[i] - halfVecs[i];

		} else if (position[i] + halfVecs[i] < otherRadius) {
			closestPoint[i] = position[i] + halfVecs[i];

		} else {
			closestPoint[i] = otherPosition [i];
		}
	}


	// calculate distance of closest point to centre of sphere
	for (int i = 0; i < 3; i++){
		XYZDistance[i] = closestPoint[i] - otherPosition[i];
		XYZDistance[i] = pow(XYZDistance[i], 2);
	}
	for (int i = 0; i < 3; i++){
		distance += XYZDistance[i];
	}
	distance = sqrt(distance);



	if (distance < otherRadius){
		collided = true;
	}

	std::cout << "COLLISON box circle" << std::endl;

	return collided;
}



bool BoundingBox::CollidesWithCircleBox(glm::vec3 position, glm::vec3 otherPosition, glm::vec3 otherHalfVecs) {
	bool collided = CollidesWithBoxCircle(otherPosition, position, this->GetRadius());
	std::cout << "circle box actually" << std::endl;
	return collided;
}



bool BoundingBox::CollidesWithCircleCircle(glm::vec3 position, glm::vec3 otherPosition, double otherRadius) {
	bool collided = false;
	glm::vec3 XYZDistance;
	double distance = 0;

	// calculate distance of closest point to centre of sphere
		for (int i = 0; i < 3; i++){
			XYZDistance[i] = position[i] - otherPosition[i];
			XYZDistance[i] = pow(XYZDistance[i], 2);
		}
		for (int i = 0; i < 3; i++){
			distance += XYZDistance[i];
		}
		distance = sqrt(distance);



		if (distance < otherRadius + this->GetRadius()){
			collided = true;
		}

	return collided;
}
