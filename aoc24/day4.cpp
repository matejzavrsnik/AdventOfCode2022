#include <gtest/gtest.h>

#include "day4.h"

using namespace aoc24;

TEST(aoc24, d4_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day4.input.txt");
   auto result = d4::p1(input);
   ASSERT_EQ(2599, result);
}

TEST(aoc24, d4_p2_cases) {
   //example
   auto result = d4::p2({
      ".M.S......",
      "..A..MSMS.",
      ".M.S.MAA..",
      "..A.ASMSM.",
      ".M.S.M....",
      "..........",
      "S.S.S.S.S.",
      ".A.A.A.A..",
      "M.M.M.M.M.",
      ".........."
   });
   ASSERT_EQ(9, result);

   // corners
   result = d4::p2({
      "M.S....M.M",
      ".A......A.",
      "M.S....S.S",
      "..........",
      "..........",
      "..........",
      "..........",
      "S.M....S.S",
      ".A......A.",
      "S.M....M.M"
   });
   ASSERT_EQ(4, result);
}

TEST(aoc24, d4_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day4.input.txt");
   auto result = d4::p2(input);
   ASSERT_LT(1886, result); // too low
   ASSERT_EQ(1948, result);
}