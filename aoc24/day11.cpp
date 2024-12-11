#include <gtest/gtest.h>

#include "day11.h"

using namespace aoc24;

TEST(aoc24, d11_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day11.input.txt");
   auto result = d11::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d11_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day11.input.txt");
   auto result = d11::p2(input);
   ASSERT_EQ(1, result);
}