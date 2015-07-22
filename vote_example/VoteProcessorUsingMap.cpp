#include "VoteProcessorUsingMap.h"


VoteProcessorUsingMap::VoteProcessorUsingMap(std::istream& inputStream, std::ostream& outputStream)
: AbstractProcessor(inputStream, outputStream) 
, counts()
, maxCandidates() {

}

VoteProcessorUsingMap::~VoteProcessorUsingMap() {

}

void VoteProcessorUsingMap::process() {
	input();
	findMaxCandidates();
	output();
}

void VoteProcessorUsingMap::findMaxCandidates() {
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
}

void VoteProcessorUsingMap::input() {
	std::istream& in = getInputStream();

	while (1) {
		std::string line;

		if (!std::getline(in, line)) {
			break;
		}

		counts[line]++;
	}
}

void VoteProcessorUsingMap::output() {
	std::ostream& out = getOutputStream();

	for (int i = 0; i < maxCandidates.size(); ++i) {
		out << maxCandidates[i] << std::endl;
	}
}