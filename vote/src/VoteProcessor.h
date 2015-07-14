/*
 * VoteProcessor.h
 *
 *  Created on: 2015. 7. 14.
 *      Author: juhee.bak
 */

#ifndef VOTEPROCESSOR_H_
#define VOTEPROCESSOR_H_

#include "Processor.h"

class VoteProcessor : public Processor {
public:
	VoteProcessor(std::istream& inputStream, std::ostream& outputStream);
	~VoteProcessor();

	void process();
};


#endif /* VOTEPROCESSOR_H_ */
