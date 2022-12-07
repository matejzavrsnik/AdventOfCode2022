#include <gtest/gtest.h>

#include "../puzzles/day3.h"

using namespace adventofcode2021;

TEST(adventofcode2021_methods, day6_bin_string_to_int)
{
   ASSERT_EQ(0, day3::bin_string_to_int("000"));
   ASSERT_EQ(1, day3::bin_string_to_int("001"));
   ASSERT_EQ(2, day3::bin_string_to_int("010"));
   ASSERT_EQ(3, day3::bin_string_to_int("011"));
   ASSERT_EQ(255, day3::bin_string_to_int("11111111"));
}
