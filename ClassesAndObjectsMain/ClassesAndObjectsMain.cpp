#include "stdafx.h"
#include "Person.h"

int main()
{
	std::wcout.imbue(std::locale("ja"));

	Person p;

	auto firstname = std::wstring(L"Kate");
	auto lastname = std::wstring(L"Gregory");
	Person p1(firstname, lastname, 11);

	{
		auto firstnameJP = std::wstring(L"剛");
		auto lastnameJP = std::wstring(L"西岡");
		Person p2(firstnameJP, lastnameJP, 11);
	}

	return 0;
}
