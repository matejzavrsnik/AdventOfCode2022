#include <gtest/gtest.h>

#include "day10.h"

using namespace aoc24;

TEST(aoc24, d10_p1_example)
{
   vec<string> input = {
      "89010123",
      "78121874",
      "87430965",
      "96549874",
      "45678903",
      "32019012",
      "01329801",
      "10456732"
   };
   auto result = d10::p1(input);
   ASSERT_EQ(36, result);
}

TEST(aoc24, d10_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day10.input.txt");
   auto result = d10::p1(input);
   ASSERT_EQ(535, result);
}

TEST(aoc24, d10_p2_example)
{
   vec<string> input = {
      "89010123",
      "78121874",
      "87430965",
      "96549874",
      "45678903",
      "32019012",
      "01329801",
      "10456732"
   };
   auto result = d10::p2(input);
   ASSERT_EQ(81, result);
}

TEST(aoc24, d10_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day10.input.txt");
   auto result = d10::p2(input);
   ASSERT_EQ(1186, result);
}