#include "VoteProcessorUsingCpp11.h"


VoteProcessorUsingCpp11::VoteProcessorUsingCpp11(std::istream& inputStream, std::ostream& outputStream)
: AbstractProcessor(inputStream, outputStream){

}

VoteProcessorUsingCpp11::~VoteProcessorUsingCpp11() {

}

void VoteProcessorUsingCpp11::process() {
	auto countingSet = countTheVoteFromInputStream();
	auto maxCandidate = findMaxCandidates(countingSet);
	printOut(maxCandidate);
}

VoteProcessorUsingCpp11::VoteCountingSet VoteProcessorUsingCpp11::countTheVoteFromInputStream() {
	std::istream& in = getInputStream();
	VoteCountingSet counts;

	while (1) {
		std::string line;

		if (!std::getline(in, line)) {
			break;
		}

		counts[line]++;
	}

	return counts;
}

VoteProcessorUsingCpp11::CandidateList VoteProcessorUsingCpp11::findMaxCandidates(const VoteCountingSet& counts) {
	CandidateList maxCandidates;
	int maxCount = 0;

	for (auto& voteCounting : counts) {
		std::string name = voteCounting.first;
		int count = voteCounting.second;

		if (count < maxCount) {
			continue;
		}

		if (count > maxCount) {
			maxCount = count;
			maxCandidates.clear();
		}

		maxCandidates.push_back(name);
	}

	return maxCandidates;
}

void VoteProcessorUsingCpp11::printOut(const CandidateList& maxCandidates) {
	std::ostream& out = getOutputStream();

	for (auto& name : maxCandidates) {
		out << name << std::endl;
	}
}