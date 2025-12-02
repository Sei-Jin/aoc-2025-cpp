#include <vector>

#include <gtest/gtest.h>
#include "days/day01.hpp"

TEST(Part2, TestRotations) {
	EXPECT_EQ(part2(std::vector{50, 150}), 2);
	EXPECT_EQ(part2(std::vector{-50, -100}), 2);
	EXPECT_EQ(part2(std::vector{-50, -50, -50, -50}), 2);
	EXPECT_EQ(part2(std::vector{50, 50, 50, 50, 50}), 3);
}