#pragma once

#include <memory>
#include <map>

#include "message_throttler_interface.hpp"

template<
	typename _ClientId,
	typename _Message,
	typename _Clock,
	typename _MessageConsumer,
	typename _MessageDisposer
>
class message_throttler
{
private:
	using _MessageThrottlerInterface = message_throttler_interface<_Message, _Clock, _MessageConsumer, _MessageDisposer>;

	using _Time = decltype(_Clock{}());
	using _Duration = decltype(_Clock{}() - _Clock{}());

public:
	message_throttler(
		std::size_t bufferSize,
		_Duration threashold,
		const _MessageConsumer& messageConsumer,
		const _MessageDisposer& messageDisposer) :
		mBufferSize(bufferSize),
		mThreashold(threashold),
		mMessageConsumer(messageConsumer),
		mMessageDisposer(messageDisposer)
	{ }

	_MessageThrottlerInterface& from(const _ClientId& clientId)
	{
		auto& client = mClients[clientId];

		if (client == nullptr)
			client = std::make_unique<_MessageThrottlerInterface>(mBufferSize, mThreashold, mMessageConsumer, mMessageDisposer);

		return *client;
	}

private:
	std::size_t mBufferSize;
	_Duration mThreashold;

	_MessageConsumer mMessageConsumer;
	_MessageDisposer mMessageDisposer;

	std::map<_ClientId, std::unique_ptr<_MessageThrottlerInterface>>  mClients;
};