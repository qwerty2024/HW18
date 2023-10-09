#include "Message.hpp"
#include "User.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;
using namespace std::filesystem;

fstream open_file(const string &filename)
{
	// /data exist?
	path dir_data = "data";
	if (!exists(dir_data))
	{
		create_directory(dir_data);
	}

	fstream file = fstream(filename, ios::in | ios::out);

	if(!file)
		file = fstream(filename, ios::in | ios::out | ios::trunc);
	
	// delete perms
	permissions(filename, perms::group_all | perms::others_all, perm_options::remove);
	
	return file;
}

template <class T>
void load_and_print(fstream &file, vector<T> &data)
{
	while(!file.eof())
	{
		string n;
		file >> n;
		string l;
		file >> l;
		string p;
		file >> p;
		cout << n << " " << l << " " << p << endl;
		T item(n, l, p);
		data.push_back(item);
	}
}

template <class T>
void enter_write_to_file(fstream &file, vector<T> &data)
{
	string one, two, three;
	cin >> one >> two >> three;

	T item(one, two, three);
	data.push_back(item);

	file.clear();
	file.seekp(0, std::ios_base::end);
	file << one << ' ' 
	     << two << ' ' 
	     << three << endl;
}

void enter_new_data(fstream &user_file, fstream &message_file, vector<User> &user_data, vector<Message> &message_data)
{
	while(1)
	{
		cout << "Enter key: user(1) or message(2) or quit(q)" << endl;
		char key;
		std::cin >> key;

		if (key == 'q') break;
		
		cout << "Enter data:\n";

		switch(key)
		{
			case '1':
				enter_write_to_file(user_file, user_data);
				break;
			case '2':
				enter_write_to_file(message_file, message_data);
				break;
			default:
				cout << "Incorrect key, re-enter please!\n";
				break;
		}
	}
}

int main()
{
	string username = getlogin();
	cout << "Hello, " << username << "!" << endl;

	string user_filename = "data/data_user_" + username + ".dat";
	string message_filename = "data/data_message_" + username + ".dat";
	//cout << user_filename << "  " << message_filename << endl;
	
	// open file if exists
	fstream user_file = open_file(user_filename);
	fstream message_file = open_file(message_filename);

	// print all load information
	vector<User> user_data; 
	vector<Message> message_data;

	cout << "\nLoaded Users:\n";
	load_and_print(user_file, user_data);

	cout << "\nLoaded Messages:\n";
	load_and_print(message_file, message_data);

	// enter new data
	enter_new_data(user_file, message_file, user_data, message_data);

	return 0;
}