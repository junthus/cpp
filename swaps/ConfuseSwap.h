#pragma once

namespace confuse {
	
	void swap(int* pA, int* pB) {
		int temp = *pA;
		*pA = *pB;
		*pB = temp;
	}

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void swap(int** dpA, int** dpB) {
		int* temp = *dpA;
		*dpA = *dpB;
		*dpB = temp;
	}

	// error - ambiguous call to overloaded function
	//void swap(int*& pA, int*& pB) {
	//	int* temp = pA;
	//	pA = pB;
	//	pB = temp;
	//}

};