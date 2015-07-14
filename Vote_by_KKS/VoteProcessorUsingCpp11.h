#pragma once

#include "AbstractProcessor.h"
#include <string>
#include <map>
#include <vector>

class VoteProcessorUsingCpp11 : public AbstractProcessor {
private :
	typedef std::map<std::string, int> VoteCountingSet;
	typedef std::vector<std::string> CandidateList;

public:
	VoteProcessorUsingCpp11(std::istream& inputStream, std::ostream& outputStream);
	~VoteProcessorUsingCpp11();

	void process();

private:
	VoteCountingSet countTheVoteFromInputStream();
	CandidateList findMaxCandidates(const VoteCountingSet& counts);
	void printOut(const CandidateList& maxCandidates);

};