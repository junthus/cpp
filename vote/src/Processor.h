/*
 * Processor.h
 *
 *  Created on: 2015. 7. 14.
 *      Author: juhee.bak
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

class Processor {
public :
	virtual ~Processor() {

	}
	virtual void process() = 0;
};

#endif /* PROCESSOR_H_ */
