/*
 * GameAsset.cc
 *
 *  Created on: 16 Dec 2016
 *      Author: stester
 */

#include "CubeAsset.h"
#include "GameAsset.h"


glm::mat4 GameAsset::getModelMatrix() {
	return model;
}

void GameAsset::translate(double x, double y, double z) {

	glm::mat4 translate;

	translate[3][0] = x;
	translate[3][1] = y;
	translate[3][2] = z;

	model *= translate;
}

void GameAsset::rotateX(double degreePerSecond) {

	degreePerSecond = degreePerSecond / 60;

	glm::mat4 xTranslate;

	xTranslate[1][1] = cos(degreePerSecond);
	xTranslate[1][2] = sin(degreePerSecond);
	xTranslate[2][1] = -sin(degreePerSecond);
	xTranslate[2][2] = cos(degreePerSecond);

	model *= xTranslate;
}

void GameAsset::rotateY(double degreePerSecond) {

	degreePerSecond = degreePerSecond / 60;

	glm::mat4 yTranslate;

	yTranslate[0][0] = cos(degreePerSecond);
	yTranslate[0][2] = -sin(degreePerSecond);
	yTranslate[2][0] = sin(degreePerSecond);
	yTranslate[2][2] = cos(degreePerSecond);

	model *= yTranslate;

}

void GameAsset::rotateZ(double degreePerSecond) {

	degreePerSecond = degreePerSecond / 60;

	glm::mat4 zTranslate;

	zTranslate[0][0] = cos(degreePerSecond);
	zTranslate[0][1] = sin(degreePerSecond);
	zTranslate[1][0] = -sin(degreePerSecond);
	zTranslate[1][1] = cos(degreePerSecond);

	model *= zTranslate;
}
