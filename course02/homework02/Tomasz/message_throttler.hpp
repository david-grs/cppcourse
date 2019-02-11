#pragma once

#include<map>
#include<memory>

#include "message_throttler_interface.hpp"

template<
	typename _ClientId,
	std::size_t _BufferSize,
	typename _Message,
	typename _MessageConsumer,
	typename _MessageDisposer,
	typename _Timestamp,
	typename _Timestamper,
	typename _TimestampThreshold,
	typename _Buffer = short_circular_buffer<_Timestamp, _BufferSize>,
	typename _MessageThrottlerInterface = message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampThreshold, _Buffer>,
	typename _Map = std::map<_ClientId, std::unique_ptr<_MessageThrottlerInterface>>
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