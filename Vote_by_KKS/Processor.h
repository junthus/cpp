#pragma once

class Processor {
public :
	virtual ~Processor() {

	}

	virtual void process() = 0;
};