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
	glm::vec3 position = glm::vec3(5, 7, 10);
	glm::vec3 otherPosition = glm::vec3(5.9, 7.9, 10.9);
	glm::vec3 otherHalfVecs = glm::vec3(0.5, 0.5, 0.5);
	double radious = 0.5;

	//test all 4 collisions, with the box only touching the corners so only box box returns a collision.
	std::cout << "FIRST ROUND" << std::endl;
	std::cout << "COLLISON - box box   ";
	bool collides = box1.CollidesWithBoxBox(position, otherPosition,  otherHalfVecs);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - circle circle   ";
	collides = box1.CollidesWithCircleCircle(position, otherPosition,  radious);
	if (collides == false){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - box circle   ";
	collides = box1.CollidesWithBoxCircle(position, otherPosition,  radious);
	if (collides == false){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - circle box   ";
	collides = box1.CollidesWithBoxCircle(position, otherPosition,  radious);
	if (collides == false){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	//test all 4 collisions, with the box touching the corners more so box box and box circle returns a collision.
	std::cout << "SECOND ROUND" << std::endl;
	otherPosition = glm::vec3(5.6, 7.6, 10.6);

	std::cout << "COLLISON - box box   ";
	collides = box1.CollidesWithBoxBox(position, otherPosition,  otherHalfVecs);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - circle circle   ";
	collides = box1.CollidesWithCircleCircle(position, otherPosition,  radious);
	if (collides == false){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - box circle   ";
	collides = box1.CollidesWithBoxCircle(position, otherPosition,  radious);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - circle box   ";
	collides = box1.CollidesWithBoxCircle(position, otherPosition,  radious);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}

	//test all 4 collisions so that it colides in all ways
	std::cout << "SECOND ROUND" << std::endl;
	otherPosition = glm::vec3(5.0, 7.0, 10.2);

	std::cout << "COLLISON - box box   ";
	collides = box1.CollidesWithBoxBox(position, otherPosition,  otherHalfVecs);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - circle circle   ";
	collides = box1.CollidesWithCircleCircle(position, otherPosition,  radious);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - box circle   ";
	collides = box1.CollidesWithBoxCircle(position, otherPosition,  radious);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}


	std::cout << "COLLISON - circle box   ";
	collides = box1.CollidesWithBoxCircle(position, otherPosition,  radious);
	if (collides == true){
		std::cout << "success!" << std::endl;
	} else{
		std::cout << "TEST FAILED" << std::endl;
	}
}
