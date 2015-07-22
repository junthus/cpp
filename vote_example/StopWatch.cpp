#include "StopWatch.h"


StopWatch::StopWatch()
: mState(State::STOPPPED)
, mFirstTimePoint()
, mSecondTimePoint()
, mStopObserver() {
}

StopWatch::StopWatch(const StopWatch& src)
: mState(src.mState)
, mFirstTimePoint(src.mFirstTimePoint)
, mSecondTimePoint(src.mSecondTimePoint)
, mStopObserver(src.mStopObserver) {
}

StopWatch::~StopWatch() {
}

StopWatch& StopWatch::operator=(const StopWatch& src) {
	mState = src.mState;
	mFirstTimePoint = src.mFirstTimePoint;
	mSecondTimePoint = src.mSecondTimePoint;
	mStopObserver = src.mStopObserver;
	return *this;
}

void StopWatch::start() {
	if (mState == State::STOPPPED) {
		mState = State::RUNNING;
		mFirstTimePoint = std::chrono::system_clock::now();
	}
	else if (mState == State::PAUSED) {
		mState = State::RUNNING;
		std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
		mFirstTimePoint += (tp - mSecondTimePoint);
	}
}

void StopWatch::restart() {
	mState = State::RUNNING;
	mFirstTimePoint = std::chrono::system_clock::now();
}

void StopWatch::pause() {
	if (mState == State::RUNNING) {
		mSecondTimePoint = std::chrono::system_clock::now();
		mState = State::PAUSED;
	}
}

void StopWatch::stop() {
	if (mState == State::STOPPPED) {
		return;
	}

	if (mState == State::PAUSED) {
		std::chrono::system_clock::time_point  tp = std::chrono::system_clock::now();
		mFirstTimePoint += (tp - mSecondTimePoint);
		mSecondTimePoint = tp;
	}
	else {
		mSecondTimePoint = std::chrono::system_clock::now();
	}

	mState = State::STOPPPED;

	if (mStopObserver) {
		mStopObserver(*this);
	}
}

int64_t StopWatch::getNanoSeconds() const {
	if (mState == State::RUNNING) {
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - mFirstTimePoint).count();
	}
	else {
		return std::chrono::duration_cast<std::chrono::nanoseconds>(mSecondTimePoint - mFirstTimePoint).count();
	}
}

int64_t StopWatch::getMicroSeconds() const {
	if (mState == State::RUNNING) {
		return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - mFirstTimePoint).count();
	}
	else {
		return std::chrono::duration_cast<std::chrono::microseconds>(mSecondTimePoint - mFirstTimePoint).count();
	}
}

int64_t StopWatch::getMilliSeconds() const {
	if (mState == State::RUNNING) {
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - mFirstTimePoint).count();
	}
	else {
		return std::chrono::duration_cast<std::chrono::milliseconds>(mSecondTimePoint - mFirstTimePoint).count();
	}
}

int64_t StopWatch::getSeconds() const {
	if (mState == State::RUNNING) {
		return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - mFirstTimePoint).count();
	}
	else {
		return std::chrono::duration_cast<std::chrono::seconds>(mSecondTimePoint - mFirstTimePoint).count();
	}
}

int64_t StopWatch::getMinutes() const {
	if (mState == State::RUNNING) {
		return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::system_clock::now() - mFirstTimePoint).count();
	}
	else {
		return std::chrono::duration_cast<std::chrono::minutes>(mSecondTimePoint - mFirstTimePoint).count();
	}
}

int64_t StopWatch::getHours() const {
	if (mState == State::RUNNING) {
		return std::chrono::duration_cast<std::chrono::hours>(std::chrono::system_clock::now() - mFirstTimePoint).count();
	}
	else {
		return std::chrono::duration_cast<std::chrono::hours>(mSecondTimePoint - mFirstTimePoint).count();
	}
}

void StopWatch::setStopObserver(std::function<void(const StopWatch&)> observer) {
	mStopObserver = observer;
}

StopWatch::State StopWatch::getState() const {
	return mState;
}