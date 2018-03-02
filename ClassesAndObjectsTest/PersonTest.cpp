#include "pch.h"

// Introduction: Why Google C++ Testing Framework ?
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#introduction-why-google-c-testing-framework

// How to reference header files in visual studio 2017 project
// https://stackoverflow.com/questions/46278306/how-to-reference-header-files-in-visual-studio-2017-project
#include "Person.h"

TEST(PersonTest, ShouldCreatePersonObject) {
	// Act
	Person p;
}
