#include "stdafx.h"
#include "Person.h"

using namespace kasumi;

Person::Person()
	: arbitrarynumber(0)
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Constructing a Person...";
}

Person::Person(std::wstring &first, std::wstring &last, int arbitrary)
	: firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Constructing a Person " << firstname << L" " << lastname << L"...";
}

Person::~Person()
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Destructing a Person " << firstname << L" " << lastname << L"...";
}

std::wstring Person::getFirstname()
{
	return firstname;
}

std::wstring Person::getLastname()
{
	return lastname;
}

int Person::getArbitrarynumber()
{
	return arbitrarynumber;
}
