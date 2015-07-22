#pragma once

#include "AbstractProcessor.h"
#include <string>
#include <map>
#include <vector>

class VoteProcessorUsingMap2 : public AbstractProcessor {
public:
	VoteProcessorUsingMap2(std::istream& inputStream, std::ostream& outputStream);
	~VoteProcessorUsingMap2();

	void process();

private:
	std::map<std::string, int> countTheVoteFromInputStream();
	std::vector<std::string> findMaxCandidates(const std::map<std::string, int>& counts);
	void printOut(const std::vector<std::string>& maxCandidates);
	
};