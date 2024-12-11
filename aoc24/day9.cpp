#include <gtest/gtest.h>

#include "day9.h"

using namespace aoc24;

TEST(aoc24, d9_p1_from_instruction)
{
   vec<string> input = {"12345"};
   auto result = d9::p1(input);
   ASSERT_EQ(60, result);
}

TEST(aoc24, d9_p1_test_case0)
{
   vec<string> input = {"101"};
   auto result = d9::p1(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d9_p1_example)
{
   vec<string> input = {"2333133121414131402"};
   auto result = d9::p1(input);
   ASSERT_EQ(1928, result);
}

TEST(aoc24, d9_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day9.input.txt");
   auto result = d9::p1(input);
   ASSERT_EQ(6461289671426, result);
}

TEST(aoc24, d9_p2_example)
{
   vec<string> input = {"2333133121414131402"};
   auto result = d9::p2(input);
   ASSERT_EQ(1, result);
}

TEST(aoc24, d9_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day9.input.txt");
   auto result = d9::p2(input);
   ASSERT_EQ(6488291456470, result);
}