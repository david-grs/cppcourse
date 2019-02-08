#pragma once

#include<map>

#include "message_throttler_interface.hpp"

template<
	typename _ClientId,
	std::size_t _BufferSize,
	typename _Message,
	typename _MessageConsumer,
	typename _MessageDisposer,
	typename _Timestamp,
	typename _Timestamper,
	typename _TimestampValidator,
	typename _MessageThrottlerInterface = message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampValidator>,
	typename _Map = std::map<_ClientId, _MessageThrottlerInterface>
>
class message_throttler
{
public:
	message_throttler(
		const _MessageConsumer& messageConsumer, 
		const _MessageDisposer& messageDisposer, 
		const _Timestamper& timestamper,
		const _TimestampValidator& timestampValidator) :
		mMessageConsumer(messageConsumer),
		mMessageDisposer(messageDisposer),
		mTimestampValidator(timestampValidator)
	{ }

	_MessageThrottlerInterface& from(const _ClientId& clientId)
	{
		return mClients.try_emplace(
			clientId, 
			mMessageConsumer, mMessageDisposer, mTimestamper, mTimestampValidator
		).first->second;
	}

private:
	_MessageConsumer mMessageConsumer;
	_MessageDisposer mMessageDisposer;

	_Timestamper mTimestamper;
	_TimestampValidator mTimestampValidator;

	_Map mClients;
};