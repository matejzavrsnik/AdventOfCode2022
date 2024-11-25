#include <gtest/gtest.h>

#include "day1.h"

using namespace aoc24;

TEST(aoc24, d1_p1)
{
   auto input = read_file_lines("./res/aoc24/day1.input.txt");
   ASSERT_NE(16671, d1::p1(input)); // too low
   ASSERT_NE(9951, d1::p1(input)); // too low
   ASSERT_EQ(54951, d1::p1(input));
}

TEST(aoc24, d1_p2)
{
   auto input = read_file_lines("./res/aoc24/day1.input.txt");
   ASSERT_NE(55086, d1::p2(input)); // too low
   ASSERT_NE(54951, d1::p2(input)); // too low
   ASSERT_NE(55514, d1::p2(input)); // too high
   ASSERT_EQ(55218, d1::p2(input));
}