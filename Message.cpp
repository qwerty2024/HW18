#include "Message.hpp"

Message::Message(string text, string sender, string receiver)
{
	_text = text;
	_sender = sender;
	_receiver = receiver;
}