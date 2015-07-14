#include "VoteProcessorUsingHash.h"
#include <algorithm>


VoteProcessorUsingHash::VoteProcessorUsingHash(std::istream& inputStream, std::ostream& outputStream)
: AbstractProcessor(inputStream, outputStream){

}

VoteProcessorUsingHash::~VoteProcessorUsingHash() {

}

void VoteProcessorUsingHash::process() {
	auto countingSet = countTheVoteFromInputStream();
	auto maxCandidate = findMaxCandidates(countingSet);
	printOut(maxCandidate);
}

VoteProcessorUsingHash::HashTable VoteProcessorUsingHash::countTheVoteFromInputStream() {
	std::istream& in = getInputStream();
	HashTable counts;
	counts.resize(BUCKET_SIZE);

	while (1) {
		std::string line;

		if (!std::getline(in, line)) {
			break;
		}

		int bucketIndex = hash(line) % BUCKET_SIZE;
		Bucket& bucket = counts[bucketIndex];
		
		//bool found = false;

		//for (auto& slot : bucket) {
		//	if (slot.first == line) {
		//		slot.second++;
		//		found = true;
		//		break;
		//	}
		//}

		//if (!found) {
		//	bucket.push_back(Slot(line, 1));
		//}

		// refactor like this
		Slot& slot = findSlotFromBucketOrChain(bucket, line);
		slot.second++;
	}

	return counts;
}

VoteProcessorUsingHash::Slot& VoteProcessorUsingHash::findSlotFromBucketOrChain(Bucket& bucket, const std::string& name) {
	for (auto& slot : bucket) {
		if (slot.first == name) {
			return slot;
		}
	}

	bucket.push_back(Slot(name, 0));
	return bucket[bucket.size() - 1];
}

unsigned int VoteProcessorUsingHash::hash(const std::string& name) {
	const unsigned int OFFSET_BASIS = 2166136261U;
	const unsigned int PRIME = 16777619U;
	unsigned int value = OFFSET_BASIS;

	for (unsigned int i = 0; i < name.length(); ++i) {
		value ^= (unsigned int)name[i];
		value *= PRIME;
	}

	return value;

	// alternate - using c++11 std
	//return std::hash<std::string>()(name);
}

VoteProcessorUsingHash::CandidateList VoteProcessorUsingHash::findMaxCandidates(const HashTable& counts) {
	CandidateList maxCandidates;
	int maxCount = 0;

	for (auto& bucket : counts) {
		for (auto& slot : bucket) {
			std::string name = slot.first;
			int count = slot.second;

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

	std::sort(maxCandidates.begin(), maxCandidates.end());
	return maxCandidates;
}

void VoteProcessorUsingHash::printOut(const CandidateList& maxCandidates) {
	std::ostream& out = getOutputStream();

	for (auto& name : maxCandidates) {
		out << name << std::endl;
	}
}