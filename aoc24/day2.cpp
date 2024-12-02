#include <gtest/gtest.h>

#include "day2.h"

using namespace aoc24;

TEST(aoc24, d2_p1_cases)
{
   auto result = d2::p1({
      "1 2 3",
      "3 2 1",
      "1 4 5",
      "1 1 3"
   });
   ASSERT_EQ(3, result);
}

TEST(aoc24, d2_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day2.input.txt");
   auto result = d2::p1(input);
   ASSERT_EQ(383, result);
}

TEST(aoc24, d2_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day2.input.txt");
   auto result = d2::p2(input);
   ASSERT_EQ(1, result);
}