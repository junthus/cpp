#pragma once

#include "AbstractProcessor.h"
#include <string>
#include <vector>

class VoteProcessorUsingHash : public AbstractProcessor {
private:
	static const int BUCKET_SIZE = 10000;

	typedef std::pair<std::string, int> Slot;
	typedef std::vector<Slot> Bucket;
	typedef std::vector<Bucket> HashTable;

	typedef std::vector<std::string> CandidateList;

public:
	VoteProcessorUsingHash(std::istream& inputStream, std::ostream& outputStream);
	~VoteProcessorUsingHash();

	void process();

private:
	HashTable countTheVoteFromInputStream();
	Slot& findSlotFromBucketOrChain(Bucket& bucket, const std::string& name);
	unsigned int hash(const std::string& name);

	CandidateList findMaxCandidates(const HashTable& counts);
	void printOut(const CandidateList& maxCandidates);
};