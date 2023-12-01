#include <gtest/gtest.h>

#include "day1.h"

using namespace aoc23;

TEST(aoc23_fun, get_all_digits_str)
{
   auto v = d1::get_all_digits_str("twone", d1::digit_names());
   ASSERT_EQ('2', v[0]);
   ASSERT_EQ('1', v[1]);
}

TEST(aoc23, d1_p1)
{
   ASSERT_NE(16671, d1::p1("./res/aoc23/day1.txt")); // too low
   ASSERT_NE(9951, d1::p1("./res/aoc23/day1.txt")); // too low
   ASSERT_EQ(54951, d1::p1("./res/aoc23/day1.txt"));
}

TEST(aoc23, d1_p2)
{
   ASSERT_NE(55086, d1::p2("./res/aoc23/day1.txt")); // too low
   ASSERT_NE(54951, d1::p2("./res/aoc23/day1.txt")); // too low
   ASSERT_NE(55514, d1::p2("./res/aoc23/day1.txt")); // too high
   ASSERT_EQ(55218, d1::p2("./res/aoc23/day1.txt"));
}