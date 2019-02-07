#pragma once

#include<map>

#include "message_throttler_interface.hpp"

template<typename _ClientId, std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
class message_throttler
{
public:
	using message_throttler_interface = message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>;

	message_throttler(_MessageConsumer& messageConsumer, _MessageDisposer& messageDisposer);

	message_throttler_interface& from(const _ClientId& clientId);

private:
	_MessageConsumer mMessageConsumer;
	_MessageDisposer mMessageDisposer;

	std::map<_ClientId, message_throttler_interface> mClients;
};

template<typename _ClientId, std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer>::message_throttler(_MessageConsumer& messageConsumer, _MessageDisposer& messageDisposer) :
	mMessageConsumer(messageConsumer),
	mMessageDisposer(messageDisposer)
{ }

template<typename _ClientId, std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>& message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer>::from(const _ClientId& clientId)
{
	return mClients.try_emplace(clientId, mMessageConsumer, mMessageDisposer).first->second;
}

template<typename _ClientId, std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer> make_message_throttler(_MessageConsumer messageConsumer, _MessageDisposer messageDisposer)
{
	return message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer>(messageConsumer, messageDisposer);
}