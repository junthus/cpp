/*
 * Hanoi.h
 *
 *  Created on: 2015. 7. 21.
 *      Author: juhee.bak
 */

class SimpleHanoi {
private:
	int moveCount;
public:
	void hanoi(int n, int from, int by, int to);
	void move(int from, int to);
	int getMoveCount();
};

