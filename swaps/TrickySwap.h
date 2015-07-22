#pragma once

namespace tricky {

	typedef int* IntPointer;

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

	void swap(IntPointer* pA, IntPointer* pB) {
		IntPointer temp = *pA;
		*pA = *pB;
		*pB = temp;
	}

	// error - ambiguous call to overloaded function
	//void swap(IntPointer& pA, IntPointer& pB) {
	//	IntPointer temp = pA;
	//	pA = pB;
	//	pB = temp;
	//}

};