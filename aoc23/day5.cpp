#include <gtest/gtest.h>

#include "day5.h"

using namespace aoc23;

TEST(aoc23, find_src)
{
   //humidity-to-location map:
   // location humidity len
   // 60       56       37
   // 56       93       4
   vec<aoc23::d5::range> ranges = {
      aoc23::d5::range{.dest=60, .src=56, .len=37},
      aoc23::d5::range{.dest=56, .src=93, .len=4}
   };
   ASSERT_EQ(56, find_src(ranges, 60));
   ASSERT_EQ(57, find_src(ranges, 61));
   ASSERT_EQ(88, find_src(ranges, 92));
   ASSERT_EQ(93, find_src(ranges, 56));
   ASSERT_EQ(94, find_src(ranges, 57));
   ASSERT_EQ(96, find_src(ranges, 59));
}

TEST(aoc23, is_a_given_seed)
{
   vec<ll> seeds = {79, 14, 55, 13};
   ASSERT_EQ(false, d5::is_a_given_seed(seeds, 78));
   ASSERT_EQ(true, d5::is_a_given_seed(seeds, 79));
   ASSERT_EQ(true, d5::is_a_given_seed(seeds, 80));
   ASSERT_EQ(true, d5::is_a_given_seed(seeds, 92));
   ASSERT_EQ(false, d5::is_a_given_seed(seeds, 93));

   ASSERT_EQ(false, d5::is_a_given_seed(seeds, 54));
   ASSERT_EQ(true, d5::is_a_given_seed(seeds, 55));
   ASSERT_EQ(true, d5::is_a_given_seed(seeds, 56));
   ASSERT_EQ(true, d5::is_a_given_seed(seeds, 67));
   ASSERT_EQ(false, d5::is_a_given_seed(seeds, 68));
}

TEST(aoc23, d5_p1)
{
   auto input = read_file_lines("./res/aoc23/day5.txt");
   ASSERT_EQ(251346198, d5::p1(input));
}

TEST(aoc23, DISABLED_d5_p2) // takes 30 seconds, don't want to run it always
{
   auto input = read_file_lines("./res/aoc23/day5.txt");
   auto result = d5::p2(input);
   ASSERT_NE(130571180, result);
   ASSERT_EQ(72263011, result);
}