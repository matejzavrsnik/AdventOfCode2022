#include <gtest/gtest.h>

#include "day7.h"

using namespace aoc23;

TEST(aoc23, lesser_hand)
{
   d7::hand l, r;
   l.cards = "4K8A6";
   r.cards = "3T8Q2";
   ASSERT_EQ(false, d7::lesser_hand(l, r));
}

TEST(aoc23, d7_p2_sample_case)
{
   vec<string> input = {
      "32T3K 765",
      "T55J5 684",
      "KK677 28",
      "KTJJT 220",
      "QQQJA 483"
   };
   auto result = d7::p2(input);
   ASSERT_EQ(5905, result);
}

TEST(aoc23, d7_p2_case1_j_is_weakest)
{
   vec<string> input = {
      "JKKK2 1",  // 2x
      "3KKK2 10", // 1x
      "QQQQ2 100" // 3x
   };
   auto result = d7::p2(input);
   ASSERT_EQ(312, result);
}

TEST(aoc23, d7_p2_case2)
{
   vec<string> input = {
      "2222J 1", // 2x
      "2J222 10" // 1x
   };
   auto result = d7::p2(input);
   ASSERT_EQ(12, result);
}

TEST(aoc23, d7_p1)
{
   auto input = read_file_lines("./res/aoc23/day7.txt");
   auto result = d7::p1(input);
   ASSERT_NE(500500, result);
   ASSERT_EQ(254024898, result);
}

TEST(aoc23, d7_p2)
{
   auto input = read_file_lines("./res/aoc23/day7.txt");
   auto result = d7::p2(input);
   ASSERT_NE(254003160, result); // too low - I wasn't using new strength scale where J is weakest
   ASSERT_EQ(254115617, result);
}