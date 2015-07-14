#pragma once

#include <iostream>
#include "Processor.h"

class AbstractProcessor : public Processor {
public:
	AbstractProcessor(std::istream& inputStream, std::ostream& outputStream);
	virtual ~AbstractProcessor();

	virtual void process() = 0;

	std::istream& getInputStream() {
		return mInputStream;
	}

	std::ostream& getOutputStream() {
		return mOutputStream;
	}

private:
	std::istream& mInputStream;
	std::ostream& mOutputStream;
};