/*
 * LiveTest.cc
 *
 *  Created on: 2 May 2017
 *      Author: stester
 */

#include "LiveTest.h"

LiveTest::LiveTest() {
	// TODO Auto-generated constructor stub

}

LiveTest::~LiveTest() {
	// TODO Auto-generated destructor stub
}

int LiveTest::run(){
	BoundingBox box1;
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 otherPosition = glm::vec3(0.9, 0.9, 0.9);
	glm::vec3 otherHalfVecs = glm::vec3(0.5, 0.5, 0.5);

	bool collides = box1.CollidesWithBoxBox(position, otherPosition,  otherHalfVecs);

	if (collides = true){
		std::cout << "sucess!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}
}
