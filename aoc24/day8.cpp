#include <gtest/gtest.h>

#include "day8.h"

using namespace aoc24;

TEST(aoc24, d8_p1_example) {
   vec<string> input = {
      "............",
      "........0...",
      ".....0......",
      ".......0....",
      "....0.......",
      "......A.....",
      "............",
      "............",
      "........A...",
      ".........A..",
      "............",
      "............"
   };
   auto result = d8::p1(input);
   ASSERT_EQ(14, result);
}

TEST(aoc24, d8_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day8.input.txt");
   auto result = d8::p1(input);
   ASSERT_EQ(336, result);
}

TEST(aoc24, d8_p2_example)
{
   vec<string> input = {
      "............",
      "........0...",
      ".....0......",
      ".......0....",
      "....0.......",
      "......A.....",
      "............",
      "............",
      "........A...",
      ".........A..",
      "............",
      "............"
   };
   auto result = d8::p2(input);
   ASSERT_EQ(34, result);
}

TEST(aoc24, d8_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day8.input.txt");
   auto result = d8::p2(input);
   ASSERT_EQ(1131, result); // 1000 too low
}