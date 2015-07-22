/*
 * Hanoi.cpp
 *
 *  Created on: 2015. 7. 22.
 *      Author: juhee.bak
 */

#include "Hanoi.h"

void Hanoi::execute(int n, int from, int by, int to) {
	if (n == 1) {
		move(from, to);
	} else {
		execute(n-1, from, to, by);
		move(from, to);
		execute(n-1, by, from, to);
	}
}

void Hanoi::move(int from, int to) {
	moveCount++;
}

