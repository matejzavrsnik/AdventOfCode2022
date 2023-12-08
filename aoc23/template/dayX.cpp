#include <gtest/gtest.h>

#include "dayX.h"

using namespace aoc23;

TEST(aoc23, dX_p1)
{
   vec<string> input = read_file_lines("./res/aoc23/dayX.txt");
   auto result = dX::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc23, dX_p2)
{
   vec<string> input = read_file_lines("./res/aoc23/dayX.txt");
   auto result = dX::p2(input);
   ASSERT_EQ(1, result);
}