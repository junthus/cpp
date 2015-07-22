#pragma once

namespace clear {
	class IntPointer {
	public :
		IntPointer(int* p) : mP(p) {

		}

		~IntPointer() {

		}

		operator int*() {
			return mP;
		}

	private :
		int* mP;
	};

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

	void swap(IntPointer& pA, IntPointer& pB) {
		IntPointer temp = pA;
		pA = pB;
		pB = temp;
	}

};