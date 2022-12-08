#include <gtest/gtest.h>

#include "../puzzles/day1.h"
#include "../puzzles/day2.h"
#include "../puzzles/day3.h"
#include "../puzzles/day4.h"
#include "../puzzles/day5.h"
#include "../puzzles/day6.h"
#include "../puzzles/day7.h"
#include "../puzzles/day8.h"

using namespace adventofcode2022;

TEST(adventofcode2022, day1_part1)
{
   ASSERT_EQ(69528, day1::part1("./res/adventofcode2022/day1.txt"));
}

TEST(adventofcode2022, day1_part2)
{
   ASSERT_EQ(206152, day1::part2("./res/adventofcode2022/day1.txt"));
}

TEST(adventofcode2022, day2_part1)
{
   ASSERT_EQ(11767, day2::part1("./res/adventofcode2022/day2.txt"));
}

TEST(adventofcode2022, day2_part2)
{
   ASSERT_EQ(13886, day2::part2("./res/adventofcode2022/day2.txt"));
}
   
TEST(adventofcode2022, day2_part2_bonus)
{
   ASSERT_EQ(13886, day2::bonus::part2("./res/adventofcode2022/day2.txt"));
}

TEST(adventofcode2022, day2_part2_bonus_v2)
{
   ASSERT_EQ(13886, day2::bonus::part2v2("./res/adventofcode2022/day2.txt"));
}

TEST(adventofcode2022, day3_part1)
{
   ASSERT_EQ(7990, day3::part1("./res/adventofcode2022/day3.txt"));
}

TEST(adventofcode2022, day3_part2)
{
   ASSERT_EQ(2602, day3::part2("./res/adventofcode2022/day3.txt"));
}

TEST(adventofcode2022, day3_part1_bonus)
{
   ASSERT_EQ(7990, day3::bonus::part1("./res/adventofcode2022/day3.txt"));
}

TEST(adventofcode2022, day3_part2_bonus)
{
   ASSERT_EQ(2602, day3::bonus::part2("./res/adventofcode2022/day3.txt"));
}

TEST(adventofcode2022, day4_part1)
{
   ASSERT_EQ(500, day4::part1("./res/adventofcode2022/day4.txt"));
}

TEST(adventofcode2022, day4_part2)
{
   ASSERT_EQ(815, day4::part2("./res/adventofcode2022/day4.txt"));
}

TEST(adventofcode2022, day4_part2_bonus)
{
   ASSERT_EQ(815, day4::bonus::part2("./res/adventofcode2022/day4.txt"));
}

TEST(adventofcode2022, day5_part1)
{
   ASSERT_EQ("FWNSHLDNZ", day5::part1("./res/adventofcode2022/day5.txt"));
}

TEST(adventofcode2022, day5_part2)
{
   ASSERT_EQ("RNRGDNFQG", day5::part2("./res/adventofcode2022/day5.txt"));
}

TEST(adventofcode2022, day6_part1)
{
   ASSERT_EQ(1093, day6::part1("./res/adventofcode2022/day6.txt"));
}

TEST(adventofcode2022, day6_part2)
{
   ASSERT_EQ(3534, day6::part2("./res/adventofcode2022/day6.txt"));
}

TEST(adventofcode2022, day6_part1_bonus)
{
   ASSERT_EQ(1093, day6::bonus::part1("./res/adventofcode2022/day6.txt"));
}

TEST(adventofcode2022, day7_part1)
{
   ASSERT_EQ(1423358, day7::part1("./res/adventofcode2022/day7.txt"));
}

TEST(adventofcode2022, day7_part2)
{
   ASSERT_EQ(545729, day7::part2("./res/adventofcode2022/day7.txt"));
}

TEST(adventofcode2022, day8_part1)
{
   ASSERT_EQ(1698, day8::part1("./res/adventofcode2022/day8.txt"));
}

TEST(adventofcode2022, day8_part2)
{
   ASSERT_EQ(672280, day8::part2("./res/adventofcode2022/day8.txt"));
}

/*
 *       TEMPLATE
 */

/*
TEST(adventofcode2022, dayX_partY)
{
   ASSERT_EQ(0, dayX::partY("./res/adventofcode2022/day8.txt"));
}
*/