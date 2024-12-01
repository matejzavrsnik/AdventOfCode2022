#include <gtest/gtest.h>

#include "day4.h"

using namespace aoc24;

TEST(aoc24, d4_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day4.input.txt");
   auto result = d4::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d4_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day4.input.txt");
   auto result = d4::p2(input);
   ASSERT_EQ(1, result);
}