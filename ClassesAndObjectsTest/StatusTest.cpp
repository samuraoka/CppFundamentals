#include "pch.h"

using namespace kasumi;

TEST(StatusTest, ShouldBePending) {
  EXPECT_EQ(0, Status::Pending);
}

TEST(StatusTest, ShouldBeApproved) {
	EXPECT_EQ(1, Status::Approved);
}

TEST(StatusTest, ShouldBeCancelled) {
	EXPECT_EQ(2, Status::Cancelled);
}
