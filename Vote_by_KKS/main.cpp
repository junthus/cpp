#include <iostream>
#include <fstream>
#include <vector>
#include "Processor.h"
#include "VoteProcessorSimple.h"
#include "VoteProcessorUsingMap.h"
#include "VoteProcessorUsingMap2.h"
#include "VoteProcessorUsingCpp11.h"
#include "VoteProcessorUsingHash.h"
#include "StopWatch.h"

void evaluate(Processor* pProcessor);

int main() {
	std::ifstream fin("10.inp");

	std::vector<Processor*> processors = {
		new VoteProcessorUsingHash(fin, std::cout),
		new VoteProcessorUsingCpp11(fin, std::cout),
		new VoteProcessorSimple(fin, std::cout)
	};

	for (auto& pProcessor : processors) {
		evaluate(pProcessor);

		fin.clear();
		fin.seekg(std::ios::beg);
	}

	fin.close();
	return 0;
}

void evaluate(Processor* pProcessor) {
	StopWatch sw;
	sw.start();

	pProcessor->process();
	delete pProcessor;

	sw.stop();
	std::cout << "elapsed time : " << sw.getMilliSeconds() << std::endl;
}