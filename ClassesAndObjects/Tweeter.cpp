#include "stdafx.h"
#include "Tweeter.h"

using namespace kasumi;
using namespace std;

Tweeter::Tweeter() : Person()
{
	auto logger = Logger::getLogger();
	BOOST_LOG_SEV(logger, debug) << L"Constructing a Tweeter...";
}

Tweeter::Tweeter(wstring first, wstring last, int arbitray, wstring handle)
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

wstring Tweeter::getTwitterHandle()
{
	return twitterhandle;
}
