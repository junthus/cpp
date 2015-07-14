#pragma once

#include "AbstractProcessor.h"
#include <string>
#include <vector>

class VoteProcessorSimple : public AbstractProcessor {
public:
	VoteProcessorSimple(std::istream& inputStream, std::ostream& outputStream);
	~VoteProcessorSimple();

	void process();

private:
	void printOut(const std::vector<std::string>& maxCandidates);
};