#pragma once

#include "Person.h"
#include <string>

class Tweeter
	: public kasumi::Person
{
private:
	std::wstring twitterhandle;

public:
	Tweeter();
	Tweeter(std::wstring &first, std::wstring &last, int arbitray, std::wstring &handle);
	virtual ~Tweeter();
	std::wstring getTwitterHandle();
};
