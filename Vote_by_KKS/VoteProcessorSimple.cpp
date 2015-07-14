#include "VoteProcessorSimple.h"
#include <vector>
#include <algorithm>


VoteProcessorSimple::VoteProcessorSimple(std::istream& inputStream, std::ostream& outputStream)
: AbstractProcessor(inputStream, outputStream){

}

VoteProcessorSimple::~VoteProcessorSimple() {

}

void VoteProcessorSimple::process() {
	std::istream& in = getInputStream();
	std::vector<std::string> names;
	std::vector<int> counts;

	while (1) {
		std::string line;

		if (!std::getline(in, line)) {
			break;
		}

		bool found = false;

		for (unsigned int i = 0; i < names.size(); ++i) {
			if (names[i] == line) {
				counts[i]++;
				found = true;
				break;
			}
		}

		if (!found) {
			names.push_back(line);
			counts.push_back(1);
		}
	}

	std::vector<std::string> maxCandidates;
	int maxCount = 0;

	for (unsigned int i = 0; i < names.size(); ++i) {
		std::string name = names[i];
		int count = counts[i];

		if (count < maxCount) {
			continue;
		}

		if (count > maxCount) {
			maxCount = count;
			maxCandidates.clear();
		}

		maxCandidates.push_back(name);
	}

	std::sort(maxCandidates.begin(), maxCandidates.end());
	printOut(maxCandidates);
}


void VoteProcessorSimple::printOut(const std::vector<std::string>& maxCandidates) {
	std::ostream& out = getOutputStream();

	for (unsigned int i = 0; i < maxCandidates.size(); ++i) {
		out << maxCandidates[i] << std::endl;
	}
}