#include <gtest/gtest.h>

#include "dayX.h"

using namespace aoc24;

TEST(aoc24, dX_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/dayX.input.txt");
   auto result = dX::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, dX_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/dayX.input.txt");
   auto result = dX::p2(input);
   ASSERT_EQ(1, result);
}