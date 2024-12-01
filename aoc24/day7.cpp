#include <gtest/gtest.h>

#include "day7.h"

using namespace aoc24;

TEST(aoc24, d7_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day7.input.txt");
   auto result = d7::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d7_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day7.input.txt");
   auto result = d7::p2(input);
   ASSERT_EQ(1, result);
}