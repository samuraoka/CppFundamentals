#include "stdafx.h"

using namespace std;
using namespace kasumi;

int main()
{
	wcout.imbue(locale("ja"));
	wcout << L"Program has been started" << endl;

	Person p;
	Person p1(L"Kate", L"Gregory", 11);

	{
		Tweeter t1(L"剛", L"西岡", 11, L"@tnishioka");
	}

	wcout << L"after innermost block" << endl;

	auto s = Pending;
	s = Approved;

	wcout << L"Program is ending..." << endl;

	return 0;
}
