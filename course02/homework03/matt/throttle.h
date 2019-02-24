#include <chrono>
#include <unordered_map>
#include <deque>
#include <string>

typedef int UserID;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<Clock> Timestamp;


struct TimestampedMessage
{
	TimestampedMessage(std::string message, Timestamp ts):
			mText(message), mArrivalTime(ts) {};

	TimestampedMessage(std::string message):
			mText(message), mArrivalTime(Clock::now()) {};

	std::string mText;
	Timestamp mArrivalTime;
};
/*
class PerUserThrottle
{
friend class Throttle;

public:
	PerUserThrottle(UserID id)

private:
	void EnqueueMessage(std::string message);
	void FlushMessages(Timestamp ts);

	std
	std::deque<TimestampedMessage> mQueue;
}
*/


class Throttle
{
public:
	void SendMessage(UserID id, std::string message);

private:
	void FlushMessages(UserID id);

	const int mMaxQueueSize = 10;
	const std::chrono::milliseconds mMessageInterval{10000};
	std::unordered_map<UserID, std::deque<TimestampedMessage>> mQueues;
};
