#include <gtest/gtest.h>

#include "day12.h"

using namespace aoc24;

TEST(aoc24, d12_p1_example)
{
   vec<string> input = {
      "RRRRIICCFF",
      "RRRRIICCCF",
      "VVRRRCCFFF",
      "VVRCCCJFFF",
      "VVVVCJJCFE",
      "VVIVCCJJEE",
      "VVIIICJJEE",
      "MIIIIIJJEE",
      "MIIISIJEEE",
      "MMMISSJEEE",
   };
   auto result = d12::p1(input);
   ASSERT_EQ(1930, result);
}

TEST(aoc24, d12_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day12.input.txt");
   auto result = d12::p1(input);
   ASSERT_EQ(1546338, result);
}

TEST(aoc24, d12_p2_example)
{
   vec<string> input = {
      "RRRRIICCFF",
      "RRRRIICCCF",
      "VVRRRCCFFF",
      "VVRCCCJFFF",
      "VVVVCJJCFE",
      "VVIVCCJJEE",
      "VVIIICJJEE",
      "MIIIIIJJEE",
      "MIIISIJEEE",
      "MMMISSJEEE",
   };
   auto result = d12::p2(input);
   ASSERT_EQ(1206, result);
}

TEST(aoc24, d12_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day12.input.txt");
   auto result = d12::p2(input);
   ASSERT_EQ(978590, result);
}