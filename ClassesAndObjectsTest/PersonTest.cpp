#include "pch.h"

// Introduction: Why Google C++ Testing Framework ?
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#introduction-why-google-c-testing-framework

using namespace kasumi;

TEST(PersonTest, ShouldCreatePersonObject) {
	// Arrange
	// Nothing to do

	// Act
	Person p;

	// Analyze
	// Nothing to do

	// Assert
	// Why is the size of an empty class in C++ not zero? [duplicate]
	// https://stackoverflow.com/questions/2362097/why-is-the-size-of-an-empty-class-in-c-not-zero
	EXPECT_EQ(88, sizeof(p));
}

TEST(PersonTest, ShouldInitializeWithDefaults) {
	// Arrange
	// Nothing to do

	// Act
	Person p;

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(std::wstring(L""), p.getFirstname());
	EXPECT_EQ(std::wstring(L""), p.getLastname());
	EXPECT_EQ(0, p.getArbitrarynumber());
}

TEST(PersonTest, ShouldInitializeFirstnameWithParams) {
	// Arrange
	// Nothing to do

	// Act
	Person p(std::wstring(L"Steven"), std::wstring(L"Pinker"), 11);

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(std::wstring(L"Steven"), p.getFirstname());
	EXPECT_EQ(std::wstring(L"Pinker"), p.getLastname());
	EXPECT_EQ(11, p.getArbitrarynumber());
}

TEST(PersonTest, ShouldInitializeFirstnameWithParamsJapanese) {
	// Arrange
	// Nothing to do

	// Act
	Person p(std::wstring(L"ƒWƒ‚ƒ“"), std::wstring(L"Ž›–å"), 11);

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(std::wstring(L"ƒWƒ‚ƒ“"), p.getFirstname());
	EXPECT_EQ(std::wstring(L"Ž›–å"), p.getLastname());
	EXPECT_EQ(11, p.getArbitrarynumber());
}
