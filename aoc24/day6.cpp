#include <gtest/gtest.h>

#include "day6.h"

using namespace aoc24;

TEST(aoc24, d6_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day6.input.txt");
   auto result = d6::p1(input);
   ASSERT_EQ(5516, result);
}

TEST(aoc24, d6_p2_example)
{
   vec<string> input =
   {
      "....#.....",
      ".........#",
      "..........",
      "..#.......",
      ".......#..",
      "..........",
      ".#..^.....",
      "........#.",
      "#.........",
      "......#..."
   };

   auto result = d6::p2(input);
   ASSERT_EQ(6, result);
}

TEST(aoc24, DISABLED_d6_p2) // disabled because long run; 3" release, 30" debug
{
   vec<string> input = read_file_lines("./res/aoc24/day6.input.txt");

   auto result = d6::p2(input);
   ASSERT_EQ(2008, result);
}