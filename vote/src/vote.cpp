//============================================================================
// Name        : vote.cpp
// Author      : bak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include "lib/StopWatch.h"
#include "Processor.h"
#include "VoteProcessor.h"


void evaluate(Processor* pProcessor);

using namespace std;

int main() {

	typedef map<string, int> freq_map;

	freq_map freq;
	string word;
	int maxFreq;
	string mostFreqItem;

	ifstream fin("cases/1.inp");

	if (!fin.is_open()) {
		cerr << "FAIL";
	}

//	while (!fin.eof() && fin >> word) {
//
//		int f = freq[word]++;
//
//		if (f > maxFreq) {
//			maxFreq = f;
//			mostFreqItem = word;
//		}
////		cout << word << endl;
//	}
//
//	cout << mostFreqItem << endl;

	Processor* pProcessor = new VoteProcessor(fin, cout);

	evaluate(pProcessor);

	fin.close();

	return 0;
}

void evaluate(Processor* pProcessor) {
	StopWatch sw;

	sw.start();

	pProcessor -> process();

	delete pProcessor;

	sw.stop();
	cout << "time: " << sw.getMilliSeconds() << endl;
}

