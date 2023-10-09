#pragma once

#include <string>

using std::string;

class Message
{
public:
	Message();
	Message(string text, string sender, string receiver);

private:
	string _text;
	string _sender;
	string _receiver;
};