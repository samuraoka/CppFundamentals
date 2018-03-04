#include "pch.h"

using namespace kasumi;

TEST(TweeterTest, ShouldCreateTweeterObject) {
	// Arrange
	// Nothing to do

	// Act
	Tweeter t;

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(136, sizeof(t));
}

TEST(TweeterTest, ShouldInitializedWithDefaults) {
	// Arrange
	// Nothing to do

	// Act
	Tweeter t;

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(std::wstring(L""), t.getFirstname());
	EXPECT_EQ(std::wstring(L""), t.getLastname());
	EXPECT_EQ(0, t.getArbitrarynumber());
	EXPECT_EQ(std::wstring(L""), t.getTwitterHandle());
}

TEST(TweeterTest, ShouldInitializedWithParams) {
	// Arrange
	// Nothing to do

	// Act
	Tweeter t(std::wstring(L"Bill"), std::wstring(L"Gates"), 777, std::wstring(L"@bgates"));

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(std::wstring(L"Bill"), t.getFirstname());
	EXPECT_EQ(std::wstring(L"Gates"), t.getLastname());
	EXPECT_EQ(777, t.getArbitrarynumber());
	EXPECT_EQ(std::wstring(L"@bgates"), t.getTwitterHandle());
}
