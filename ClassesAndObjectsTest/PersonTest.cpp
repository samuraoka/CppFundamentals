#include "pch.h"

// Introduction: Why Google C++ Testing Framework ?
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#introduction-why-google-c-testing-framework

// How to reference header files in visual studio 2017 project
// https://stackoverflow.com/questions/46278306/how-to-reference-header-files-in-visual-studio-2017-project
#include "Person.h"

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
	EXPECT_EQ(1, sizeof(p));
}
