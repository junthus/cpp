#include <iostream>
#include <iomanip>
#include "ConfuseSwap.h"
#include "TrickySwap.h"
#include "ClearSwap.h"
#include "NiceSwap.h"

// old c style macro. bad usage
#define SWAP(a, b, t) {t = a; a = b; b = t;}
#define SWAP_INT(a, b) {int t; SWAP(a, b, t);}
#define SWAP_INT_POINTER(a, b) {int* t; SWAP(a, b, t)}



void testBad(int a, int b);
void testConfuse(int a, int b);
void testTricky(int a, int b);
void testClear(int a, int b);
void testNice(int a, int b);
void testOld(int a, int b);

void printTag(const char* tag);
void printValueAndAddress(int a, int b, int* pA, int*pB);


int main() {	
	int a = 2;
	int b = 4;

	//testBad(a, b);
	//testConfuse(a, b);
	//testTricky(a, b);
	testClear(a, b);
//	testNice(a, b);
//	testOld(a, b);

	return 0;
}


void testBad(int a, int b) {
	int* pA = &a;
	int* pB = &b;

	printTag("- before -");
	printValueAndAddress(a, b, pA, pB);

	SWAP_INT(a, b);
	//SWAP_INT_POINTER(pA, pB);

	printTag("\n- after -");
	printValueAndAddress(a, b, pA, pB);
}



void testConfuse(int a, int b) {
	using namespace confuse;

	int* pA = &a;
	int* pB = &b;

	printTag("- before -");
	printValueAndAddress(a, b, pA, pB);

	swap(&a, &b);
	//swap(a, b);
	//swap(&pA, &pB);
	//swap(pA, pB); // not working

	printTag("\n- after -");
	printValueAndAddress(a, b, pA, pB);
}

void testTricky(int a, int b) {
	using namespace tricky;

	IntPointer pA = &a;
	IntPointer pB = &b;

	printTag("- before -");
	printValueAndAddress(a, b, pA, pB);

	swap(&a, &b);
	//swap(a, b);
	//swap(&pA, &pB);
	//swap(pA, pB); // not working

	printTag("\n- after -");
	printValueAndAddress(a, b, pA, pB);
}

void testClear(int a, int b) {
	using namespace clear;

	IntPointer pA = &a;
	IntPointer pB = &b;

	printTag("- before -");
	printValueAndAddress(a, b, pA, pB);

	swap(&a, &b);
	//swap(a, b);
	//swap(&pA, &pB);
	//swap(pA, pB);

	printTag("\n- after -");
	printValueAndAddress(a, b, pA, pB);
}

void testNice(int a, int b) {
	using namespace nice;

	int* pA = &a;
	int* pB = &b;

	printTag("- before -");
	printValueAndAddress(a, b, pA, pB);
	
//	swap(a, b); //template type: int
	swap(pA, pB); //template type: int*

	printTag("\n- after -");
	printValueAndAddress(a, b, pA, pB);
}

void testOld(int a, int b) {
	printTag("- before -");
	printValueAndAddress(a, b, nullptr, nullptr);

	a ^= b ^= a ^= b;

	// alternate
	//a = a ^ b;
	//b = b ^ a;
	//a = b ^ a;

	printTag("\n- after -");
	printValueAndAddress(a, b, nullptr, nullptr);
}


void printTag(const char* tag) {
	std::cout << tag << std::endl;
}

void printValueAndAddress(int a, int b, int* pA, int*pB) {
	using namespace std;
	
	cout << setw(6) << "a = " << setw(8) << a;
	cout << setw(10) << "b = " << setw(8) << b << endl;
	
	if (pA == nullptr || pB == nullptr) {
		return;
	}

	cout << setw(6) << "*pA = " << setw(8) << *pA;
	cout << setw(10) << "*pB = " << setw(8) << *pB << endl;
	
	cout << setw(6) << "pA = " << setw(8) << pA;
	cout << setw(10) << "pB = " << setw(8) << pB << endl;
}

