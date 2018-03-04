#include "stdafx.h"
#include "Person.h"

using namespace kasumi;
using namespace std;

Person::Person()
	: arbitrarynumber(0)
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Constructing a Person...";
}

Person::Person(wstring first, wstring last, int arbitrary)
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

wstring Person::getFirstname()
{
	return firstname;
}

wstring Person::getLastname()
{
	return lastname;
}

int Person::getArbitrarynumber()
{
	return arbitrarynumber;
}
