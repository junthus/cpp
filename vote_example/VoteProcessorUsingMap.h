#pragma once

#include "AbstractProcessor.h"
#include <string>
#include <map>
#include <vector>

class VoteProcessorUsingMap : public AbstractProcessor {
public :
	VoteProcessorUsingMap(std::istream& inputStream, std::ostream& outputStream);
	~VoteProcessorUsingMap();

	void process();

private :
	void input();
	void findMaxCandidates();
	void output();

private :
	std::map<std::string, int> counts;
	std::vector<std::string> maxCandidates;
};