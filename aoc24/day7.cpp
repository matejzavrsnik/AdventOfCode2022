#include <gtest/gtest.h>

#include "day7.h"

using namespace aoc24;

TEST(aoc24, d7_p1_example) {
   vec<string> input = {
      "190: 10 19",
      "3267: 81 40 27",
      "83: 17 5",
      "156: 15 6",
      "7290: 6 8 6 15",
      "161011: 16 10 13",
      "192: 17 8 14",
      "21037: 9 7 18 13",
      "292: 11 6 16 20",
   };
   auto result = d7::p1(input);
   ASSERT_EQ(3749, result);
}

TEST(aoc24, d7_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day7.input.txt");
   auto result = d7::p1(input);
   ASSERT_EQ(663613490587, result);
}

TEST(aoc24, d7_p2_example) {
   vec<string> input = {
      "190: 10 19",
      "3267: 81 40 27",
      "83: 17 5",
      "156: 15 6",
      "7290: 6 8 6 15",
      "161011: 16 10 13",
      "192: 17 8 14",
      "21037: 9 7 18 13",
      "292: 11 6 16 20",
   };
   auto result = d7::p2(input);
   ASSERT_EQ(11387, result);
}

TEST(aoc24, d7_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day7.input.txt");
   auto result = d7::p2(input);
   ASSERT_EQ(110365987435001, result);
}