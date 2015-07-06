#include <chrono>
#include <functional>

class StopWatch {
public:
	enum class State : uint8_t {
		UNDEFINED = 0	///< 미정의
		, RUNNING		///< 시간 진행중
		, PAUSED		///< 일시 정지 상태
		, STOPPPED		///< 정지 상태
	};

	StopWatch();
	StopWatch(const StopWatch& src);
	~StopWatch();

	StopWatch& operator=(const StopWatch& src);

	void start();

	void restart();
	void stop();
	void pause();
	int64_t getNanoSeconds() const;
	int64_t getMicroSeconds() const;
	int64_t getMilliSeconds() const;
	int64_t getSeconds() const;
	int64_t getMinutes() const;
	int64_t getHours() const;

	void setStopObserver(std::function<void(const StopWatch&)> observer);
	State getState() const;

private:
	State mState;
	std::chrono::system_clock::time_point mFirstTimePoint;
	std::chrono::system_clock::time_point mSecondTimePoint;
	std::function<void(StopWatch&)> mStopObserver;
};
