#include <gtest/gtest.h>

#include "day13.h"

using namespace aoc24;

TEST(aoc24, d13_p1_example)
{
   vec<string> input = {
      "Button A: X+94, Y+34",
      "Button B: X+22, Y+67",
      "Prize: X=8400, Y=5400",
      "",
      "Button A: X+26, Y+66",
      "Button B: X+67, Y+21",
      "Prize: X=12748, Y=12176",
      "",
      "Button A: X+17, Y+86",
      "Button B: X+84, Y+37",
      "Prize: X=7870, Y=6450",
      "",
      "Button A: X+69, Y+23",
      "Button B: X+27, Y+71",
      "Prize: X=18641, Y=10279"
   };
   auto result = d13::p1(input);
   ASSERT_EQ(480, result);
}

TEST(aoc24, d13_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day13.input.txt");
   auto result = d13::p1(input);
   ASSERT_EQ(29598, result);
}

TEST(aoc24, d13_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day13.input.txt");
   auto result = d13::p2(input);
   ASSERT_EQ(1, result);
}