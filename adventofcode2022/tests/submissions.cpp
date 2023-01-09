#include <gtest/gtest.h>

#include "../puzzles/day1.h"
#include "../puzzles/day2.h"
#include "../puzzles/day3.h"
#include "../puzzles/day4.h"
#include "../puzzles/day5.h"
#include "../puzzles/day6.h"
#include "../puzzles/day7.h"
#include "../puzzles/day8.h"
#include "../puzzles/day9.h"
#include "../puzzles/day10.h"
#include "../puzzles/day11.h"
#include "../puzzles/day12.h"

#include "../puzzles/day14.h"
#include "../puzzles/day15.h"
#include "../puzzles/day16.h"
#include "../puzzles/day17.h"

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

TEST(adventofcode2022, day9_part1)
{
   ASSERT_EQ(6494, day9::part1("./res/adventofcode2022/day9.txt"));
}

TEST(adventofcode2022, day9_part2)
{
   ASSERT_EQ(2691, day9::part2("./res/adventofcode2022/day9.txt"));
}

TEST(adventofcode2022, day10_part1)
{
   ASSERT_EQ(15120, day10::part1("./res/adventofcode2022/day10.txt"));
}

TEST(adventofcode2022, day10_part2)
{
   auto screen = day10::part2("./res/adventofcode2022/day10.txt");
   ASSERT_EQ(6, screen.size());
   ASSERT_EQ("###  #  # ###    ## ###  ###  #     ##  ", screen[0]);
   ASSERT_EQ("#  # # #  #  #    # #  # #  # #    #  # ", screen[1]);
   ASSERT_EQ("#  # ##   #  #    # ###  #  # #    #  # ", screen[2]);
   ASSERT_EQ("###  # #  ###     # #  # ###  #    #### ", screen[3]);
   ASSERT_EQ("# #  # #  #    #  # #  # #    #    #  # ", screen[4]);
   ASSERT_EQ("#  # #  # #     ##  ###  #    #### #  # ", screen[5]);
}

TEST(adventofcode2022, day11_part1)
{
   ASSERT_EQ(69918, day11::part1("./res/adventofcode2022/day11.txt"));
}

TEST(adventofcode2022, day11_part2)
{
   ASSERT_EQ(0, day11::part2("./res/adventofcode2022/day11.txt"));
}

TEST(adventofcode2022, day12_part1)
{
   ASSERT_EQ(472, day12::part1("./res/adventofcode2022/day12.txt"));
}

TEST(adventofcode2022, day12_part2)
{
   ASSERT_EQ(465, day12::part2("./res/adventofcode2022/day12.txt"));
}

TEST(adventofcode2022, day14_part1)
{
   ASSERT_EQ(0, day14::part1("./res/adventofcode2022/day14.txt"));
}

TEST(adventofcode2022, day14_part2)
{
   ASSERT_EQ(0, day14::part2("./res/adventofcode2022/day14.txt"));
}

TEST(adventofcode2022, day15_part1)
{
   ASSERT_EQ(4725496, day15::part1("./res/adventofcode2022/day15.txt"));
}

TEST(adventofcode2022, day15_part2)
{
   // disabled because it takes 13 seconds
   ASSERT_EQ(12051287042458, day15::part2("./res/adventofcode2022/day15.txt"));
}

TEST(adventofcode2022, day16_part1)
{
   ASSERT_EQ(0, day16::part1("./res/adventofcode2022/day16.txt"));
}

TEST(adventofcode2022, day16_part2)
{
   ASSERT_EQ(0, day16::part2("./res/adventofcode2022/day16.txt"));
}

TEST(adventofcode2022, day17_part1)
{
   ASSERT_EQ(3161, day17::part1("./res/adventofcode2022/day17.txt"));
}

TEST(DISABLED_adventofcode2022, day17_part2)
{
   ASSERT_EQ(0, day17::part2("./res/adventofcode2022/day17.txt"));
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