#include "stdafx.h"
#include "Tweeter.h"

using namespace kasumi;

Tweeter::Tweeter() : Person()
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Constructing a Tweeter...";
}

Tweeter::Tweeter(std::wstring &first, std::wstring &last, int arbitray, std::wstring &handle)
	: Person(first, last, arbitray), twitterhandle(handle)
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Constructing a Tweeter" << twitterhandle << "...";
}

Tweeter::~Tweeter()
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Destructing a Tweeter" << twitterhandle << "...";
}

std::wstring Tweeter::getTwitterHandle()
{
	return twitterhandle;
}
