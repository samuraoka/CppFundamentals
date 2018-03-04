#include "stdafx.h"

using namespace std;
using namespace kasumi;

int main()
{
	wcout.imbue(locale("ja"));
	wcout << L"Program has been started" << endl;

	Person p;

	auto firstname = wstring(L"Kate");
	auto lastname = wstring(L"Gregory");
	Person p1(firstname, lastname, 11);

	{
		auto firstnameJP = wstring(L"剛");
		auto lastnameJP = wstring(L"西岡");
		auto handle = wstring(L"@tnishioka");
		Tweeter p2(firstnameJP, lastnameJP, 11, handle);
	}

	wcout << L"after innermost block" << endl;
	wcout << L"Program is ending.." << endl;

	return 0;
}
