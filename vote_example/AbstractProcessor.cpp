#include "AbstractProcessor.h"

AbstractProcessor::AbstractProcessor(std::istream& inputStream, std::ostream& outputStream)
: mInputStream(inputStream)
, mOutputStream(outputStream) {

}

AbstractProcessor::~AbstractProcessor() {

}