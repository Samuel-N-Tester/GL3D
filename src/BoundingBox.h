#include <glm/glm.hpp>
#include <iostream>

/*
 * BoundingBox.h
 *
 *  Created on: 21 Feb 2017
 *      Author: stester
 */

#ifndef SRC_BOUNDINGBOX_H_
#define SRC_BOUNDINGBOX_H_

class BoundingBox {
private:
	glm::vec3 halfX = glm::vec3 (0.5, 0,   0);
	glm::vec3 halfY = glm::vec3 (0,   0.5, 0);
	glm::vec3 halfZ = glm::vec3 (0,   0,   0.5);
	double radius = 0.5;

public:
	BoundingBox();
	virtual ~BoundingBox();

	glm::vec3 GetSizeVec();
	bool CollidesWithBoxBox(glm::vec3, glm::vec3, glm::vec3);
	bool CollidesWithBoxCircle(glm::vec3, glm::vec3, double);
	bool CollidesWithCircleBox(glm::vec3, glm::vec3, glm::vec3);
	bool CollidesWithCircleCircle(glm::vec3, glm::vec3, double);
	double GetRadius();
};

#endif /* SRC_BOUNDINGBOX_H_ */
