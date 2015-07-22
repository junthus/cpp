/*
 * Hanoi.h
 *
 *  Created on: 2015. 7. 22.
 *      Author: juhee.bak
 */

#ifndef HANOI_H_
#define HANOI_H_

class Hanoi {
private:

public:
	int moveCount;
	void execute(int n, int from, int by, int to);
	void move(int from, int to);
};

#endif /* HANOI_H_ */
