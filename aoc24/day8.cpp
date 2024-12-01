#include <gtest/gtest.h>

#include "day8.h"

using namespace aoc24;

TEST(aoc24, d8_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day8.input.txt");
   auto result = d8::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d8_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day8.input.txt");
   auto result = d8::p2(input);
   ASSERT_EQ(1, result);
}