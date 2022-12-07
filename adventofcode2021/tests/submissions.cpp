#include <gtest/gtest.h>

#include "../puzzles/day1.h"
#include "../puzzles/day2.h"
#include "../puzzles/day3.h"
#include "../puzzles/day4.h"
#include "../puzzles/day5.h"
#include "../puzzles/day6.h"

using namespace adventofcode2021;

TEST(adventofcode2021, day1_part1)
{
   ASSERT_EQ(1139, day1::part1("./res/adventofcode2021/day1.txt"));
}

TEST(adventofcode2021, day1_part2)
{
   ASSERT_EQ(1103, day1::part2("./res/adventofcode2021/day1.txt"));
}

TEST(adventofcode2021, day2_part1)
{
   ASSERT_EQ(2091984, day2::part1("./res/adventofcode2021/day2.txt"));
}

TEST(adventofcode2021, day2_part2)
{
   ASSERT_EQ(2086261056, day2::part2("./res/adventofcode2021/day2.txt"));
}

TEST(adventofcode2021, day3_part1)
{
   ASSERT_EQ(3912944, day3::part1("./res/adventofcode2021/day3.txt"));
}

TEST(adventofcode2021, day3_part2)
{
   ASSERT_EQ(0, day3::part2("./res/adventofcode2021/day3.txt"));
}

TEST(adventofcode2021, day4_part1)
{
   ASSERT_EQ(0, day4::part1("./res/adventofcode2021/day4.txt"));
}

TEST(adventofcode2021, day4_part2)
{
   ASSERT_EQ(0, day4::part2("./res/adventofcode2021/day4.txt"));
}

TEST(adventofcode2021, day5_part1)
{
   ASSERT_EQ(0, day5::part1("./res/adventofcode2021/day5.txt"));
}

TEST(adventofcode2021, day5_part2)
{
   ASSERT_EQ(0, day5::part2("./res/adventofcode2021/day5.txt"));
}

TEST(adventofcode2021, day6_part1)
{
   ASSERT_EQ(0, day6::part1("./res/adventofcode2021/day6.txt"));
}

TEST(adventofcode2021, day6_part2)
{
   ASSERT_EQ(0, day6::part2("./res/adventofcode2021/day6.txt"));
}