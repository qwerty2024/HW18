#pragma once

#include <string>

using std::string;

class User
{
public:
	User();
	User(string name, string login, string pass);

private:
	string _name;
	string _login;
	string _pass;
};