#include "VoteProcessorUsingMap2.h"


VoteProcessorUsingMap2::VoteProcessorUsingMap2(std::istream& inputStream, std::ostream& outputStream)
: AbstractProcessor(inputStream, outputStream){

}

VoteProcessorUsingMap2::~VoteProcessorUsingMap2() {

}

void VoteProcessorUsingMap2::process() {
	printOut(findMaxCandidates(countTheVoteFromInputStream()));
}

std::map<std::string, int> VoteProcessorUsingMap2::countTheVoteFromInputStream() {
	std::istream& in = getInputStream();
	std::map<std::string, int> counts;

	while (1) {
		std::string line;

		if (!std::getline(in, line)) {
			break;
		}

		counts[line]++;
	}

	return counts;
}

std::vector<std::string> VoteProcessorUsingMap2::findMaxCandidates(const std::map<std::string, int>& counts) {
	std::vector<std::string> maxCandidates;
	int maxCount = 0;

	for (std::map<std::string, int>::const_iterator pos = counts.begin(); pos != counts.end(); ++pos) {
		std::string name = pos->first;
		int count = pos->second;

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

void VoteProcessorUsingMap2::printOut(const std::vector<std::string>& maxCandidates) {
	std::ostream& out = getOutputStream();

	for (int i = 0; i < maxCandidates.size(); ++i) {
		out << maxCandidates[i] << std::endl;
	}
}