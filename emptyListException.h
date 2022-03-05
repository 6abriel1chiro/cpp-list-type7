#pragma once

#include <sstream>
#include <iostream>
using namespace std;

class emptyListException : public exception
{
private:
	string msg;
public:
	emptyListException() {
		stringstream ss;
		ss << "empty list";
		msg = ss.str();
	}
	const char* what() const throw ()
	{
		return msg.c_str();
	}
};


