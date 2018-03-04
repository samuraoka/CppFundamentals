#include "stdafx.h"
#include "Person.h"

Person::Person()
	: arbitrarynumber(0)
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"constructing" << std::endl;
}

Person::Person(std::wstring &first, std::wstring &last, int arbitrary)
	: firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"constructing " << firstname << L" " << lastname << std::endl;
}

Person::~Person()
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"destructing " << firstname << L" " << lastname << std::endl;
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
