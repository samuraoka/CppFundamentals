#include "pch.h"

TEST(StdStringTest, ShouldHaveSize) {
	// Arrange
	// Nothing to do

	// Act
	std::wstring s;

	// Analyze
	// Nothing to do

	// Assert
	EXPECT_EQ(40, sizeof(s));
}
