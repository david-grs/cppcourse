#include "throttle.h"

typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<double> fsec;

template<class duration>
double DurationToMillis(duration d)
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(d).count();
}

void Throttle::SendMessage(UserID id, std::string message)
{
	FlushMessages(id);
	
	TimestampedMessage tsm{message};
	auto& queue = mQueues[id];

	Timestamp arrivalTime = Clock::now();

	auto timeBetweenFirstLast = arrivalTime - queue.front().mArrivalTime;
	auto timeToWait = mMessageInterval - timeBetweenFirstLast;
	double millisToWait = DurationToMillis(timeToWait);

	if(queue.size() >= mMaxQueueSize)
	{
		printf("user %d message %s dropped, please wait %.0f millis  \n", id, message.c_str(), millisToWait);
	}
	else
	{
		printf("user %d message %s accepted  \n", id, message.c_str());
		queue.emplace_back(TimestampedMessage{message, arrivalTime});
	}
}

void Throttle::FlushMessages(UserID id)
{
	auto& queue = mQueues[id];
	Timestamp now = Clock::now();
	while (!queue.empty())
	{
		if (now - queue.front().mArrivalTime > mMessageInterval)
		{
			printf("user %d message %s popping \n", id, queue.front().mText.c_str());
			queue.pop_front();
		}
		else
			break;
	}
}
