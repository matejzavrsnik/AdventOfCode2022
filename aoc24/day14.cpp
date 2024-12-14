#include <gtest/gtest.h>

#include "day14.h"

using namespace aoc24;

TEST(aoc24, d14_move_coordinate) {
   //  0  1  2  3  4  5  6  7  8  9
   // [ ][ ][ ][ ][ ][x][ ][ ][ ][ ]

   // positive directions
   // [ ][ ][ ][ ][ ][x][ ][ ][ ][ ]
   ASSERT_EQ(5, d14::move_coordinate(5, 0, 10, 5));
   // [ ][ ][ ][ ][ ][ ][x][ ][ ][ ]
   ASSERT_EQ(6, d14::move_coordinate(5, 1, 10, 1));
   // [ ][ ][ ][ ][ ][ ][ ][ ][ ][x]
   ASSERT_EQ(9, d14::move_coordinate(5, 1, 10, 4));
   // [x][ ][ ][ ][ ][ ][ ][ ][ ][ ]
   ASSERT_EQ(0, d14::move_coordinate(5, 1, 10, 5));
   // [ ][x][ ][ ][ ][ ][ ][ ][ ][ ]
   ASSERT_EQ(1, d14::move_coordinate(5, 1, 10, 6));
   // [ ][ ][ ][ ][ ][ ][ ][x][ ][ ]
   ASSERT_EQ(7, d14::move_coordinate(5, 2, 10, 1));

   // negative directions
   // [ ][ ][ ][ ][x][ ][ ][ ][ ][ ]
   ASSERT_EQ(4, d14::move_coordinate(5, -1, 10, 1));
   // [x][ ][ ][ ][ ][ ][ ][ ][ ][ ]
   ASSERT_EQ(0, d14::move_coordinate(5, -1, 10, 5));
   // [ ][ ][ ][ ][ ][ ][ ][ ][ ][x]
   ASSERT_EQ(9, d14::move_coordinate(5, -1, 10, 6));
   // [ ][ ][ ][ ][ ][ ][ ][ ][x][ ]
   ASSERT_EQ(8, d14::move_coordinate(5, -1, 10, 7));
   // [ ][ ][ ][ ][ ][ ][ ][x][ ][ ]
   ASSERT_EQ(3, d14::move_coordinate(5, -2, 10, 1));

}

TEST(aoc24, d14_p1_example)
{
   vec<string> input = {
      "p=0,4 v=3,-3",
      "p=6,3 v=-1,-3",
      "p=10,3 v=-1,2",
      "p=2,0 v=2,-1",
      "p=0,0 v=1,3",
      "p=3,0 v=-2,-2",
      "p=7,6 v=-1,-3",
      "p=3,0 v=-1,-2",
      "p=9,3 v=2,3",
      "p=7,3 v=-1,2",
      "p=2,4 v=2,-3",
      "p=9,5 v=-3,-3"
   };
   auto result = d14::p1(input, 11, 7);
   ASSERT_EQ(12, result);
}

TEST(aoc24, d14_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day14.input.txt");
   auto result = d14::p1(input, 101, 103);
   ASSERT_EQ(231221760, result);
}

TEST(aoc24, d14_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day14.input.txt");
   auto result = d14::p2(input, 101, 103);
   // I made it pass the test in standard way but I admit I did it visually
   // I guess I could do it in an automated way because the patterns must start to repeat
   // and through that I could determine that symetry will never be below something and
   // that could be a queue to stop iterating - but I had the result already.
   ASSERT_EQ(6771, result);
}