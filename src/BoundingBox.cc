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

glm::vec3 BoundingBox::GetSizeVec(){
	return halfX + halfY + halfZ;
}


bool BoundingBox::CollidesWith(glm::vec3 otherPosition, glm::vec3 otherHalfVecs){


	return true;
}
