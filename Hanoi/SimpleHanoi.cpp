/*
 * SimpleHanoi.cpp
 *
 *  Created on: 2015. 7. 21.
 *      Author: juhee.bak
 */

#include "SimpleHanoi.h"
//#include <iostream>

void SimpleHanoi::hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		move(from, to);
	} else {
		hanoi(n-1, from, to, by);
		move(from, to);
		hanoi(n-1, by, from, to);
	}
}

void SimpleHanoi::move(int from, int to) {
//	std::cout << moveCount<< std::endl;
	moveCount++;
}

int SimpleHanoi::getMoveCount() {
	return moveCount;
}
