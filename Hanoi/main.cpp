/*
 * main.cpp
 *
 *  Created on: 2015. 7. 21.
 *      Author: juhee.bak
 */
#include <iostream>
/*
#include "Cost.h"

using namespace std;

int main() {
	int numOfDisk;

	Cost c;

	cin >> numOfDisk;

	c.execute(numOfDisk, 1, 2, 3);

	cout << c.getMoveCount() << endl;

	return 0;
}
*/


#include "SimpleHanoi.h"

using namespace std;

void hanoi(int n, int from, int by, int to);
void move(int from, int to);

int main () {

	int numOfDisk;

	SimpleHanoi sh;

	cout << "원판의 개수를 입력: ";
	cin >> numOfDisk;

	sh.hanoi(numOfDisk, 1, 2, 3);

	int mc = sh.getMoveCount();

//	hanoi(numOfDisk, 1, 2, 3);
//	cout << "cost: " << moveCount << endl;

	cout << mc << endl;

	return 0;
}



//Cost
/*
using namespace std;

void hanoi(int n, int from, int by, int to);
void move(int from, int to);

static int moveCount = 0;

int main () {
	int numOfDisk;

	cin >> numOfDisk;
	hanoi(numOfDisk, 1, 2, 3);
	cout << moveCount << endl;

	return 0;
}

//1에서 n-1 개를 2로
//1에서 1개를 3으로
//2에서 n-1개를 3으로
void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		move(from, to);
	} else {
		hanoi(n-1, from, to, by);
		move(from, to);
		hanoi(n-1, by, from, to);
	}
}

void move(int from, int to) {
	//cout << "from:" << from << " -> to:" << to << endl;
	moveCount++;
}
*/

//Monitor
/*
using namespace std;

void hanoi(int n, int from, int by, int to);
bool move(int from, int to);
void printResult(int from, int to);

static int moveCount = 0;
static int targetTurn = 0;
static int numOfDisk = 0;
static bool flag = true;

int main () {
	cin >> numOfDisk;
	cin >> targetTurn;

	hanoi(numOfDisk, 1, 2, 3);

	if (targetTurn > moveCount) {
		cout << "already completed" << endl;
	}
//	cout << moveCount << endl;

	return 0;
}

//1에서 n-1 개를 2로
//1에서 1개를 3으로
//2에서 n-1개를 3으로
void hanoi(int n, int from, int by, int to) {
	if (flag) {
		if (n == 1) {
			flag = move(from, to);
		} else {
			hanoi(n-1, from, to, by);
			flag = move(from, to);
			hanoi(n-1, by, from, to);
		}
	}
}

bool move(int from, int to) {
	//cout << "from:" << from << " -> to:" << to << endl;
	bool flag = true;

	moveCount++;

	if (moveCount == targetTurn) {
		printResult(from, to);
		flag = false;
	}


	return flag;
}

void printResult(int from, int to) {
	cout <<  numOfDisk << " disk (" << from << " => " << to << ")" << endl;
}

*/
