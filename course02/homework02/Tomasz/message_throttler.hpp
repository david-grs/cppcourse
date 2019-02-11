#pragma once

#include<memory>

template<
	typename _ClientId,
	typename _Message,
	typename _MessageConsumer,
	typename _MessageDisposer,
	typename _Timestamp,
	typename _Timestamper,
	typename _TimestampThreshold,
	typename _MessageThrottlerInterface,
	typename _Map
>
class message_throttler
{
public:
	message_throttler(
		const _MessageConsumer& messageConsumer, 
		const _MessageDisposer& messageDisposer, 
		const _Timestamper& timestamper,
		const _TimestampThreshold& timestampThreshold) :
		mMessageConsumer(messageConsumer),
		mMessageDisposer(messageDisposer),
		mTimestamper(timestamper),
		mTimestampThreshold(timestampThreshold)
	{ }

	_MessageThrottlerInterface& from(const _ClientId& clientId)
	{
		auto element = mClients.emplace(clientId, nullptr);
		auto& client = element.first->second;

		if (element.second)
			client = std::make_unique<_MessageThrottlerInterface>(mMessageConsumer, mMessageDisposer, mTimestamper, mTimestampThreshold);

		return *client;
	}

private:
	_MessageConsumer mMessageConsumer;
	_MessageDisposer mMessageDisposer;

	_Timestamper mTimestamper;
	_TimestampThreshold mTimestampThreshold;

	_Map mClients;
};