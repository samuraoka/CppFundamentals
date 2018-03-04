#pragma once

#include <string>

namespace kasumi
{
	class Person
	{
	public:
		Person();
		Person(std::wstring first, std::wstring last, int arbitrary);
		~Person();

		std::wstring getFirstname();
		std::wstring getLastname();
		int getArbitrarynumber();

	private:
		std::wstring firstname;
		std::wstring lastname;
		int arbitrarynumber;
	};
}
