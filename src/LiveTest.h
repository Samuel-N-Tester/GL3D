/*
 * LiveTest.h
 *
 *  Created on: 2 May 2017
 *      Author: stester
 */

#include <BoundingBox.h>

#ifndef SRC_LiveTEST_H_
#define SRC_LiveTEST_H_

class LiveTest {
public:
	LiveTest();
	virtual ~LiveTest();
	int run();
	int echo();
	int add(int, int);
};

#endif /* SRC_LiveTEST_H_ */
