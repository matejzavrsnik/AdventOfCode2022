#include <gtest/gtest.h>

#include "day5.h"

using namespace aoc24;

TEST(aoc24, d5_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day5.input.txt");
   auto result = d5::p1(input);
   ASSERT_EQ(4790, result);
}

TEST(aoc24, d5_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day5.input.txt");
   auto result = d5::p2(input);
   ASSERT_EQ(6319, result);
}