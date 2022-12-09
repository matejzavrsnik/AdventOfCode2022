#include <gtest/gtest.h>

#include "../puzzles/day6.h"
#include "../puzzles/day8.h"
#include "../puzzles/day9.h"

using namespace adventofcode2022;

TEST(adventofcode2022_methods, day6_is_marker)
{
   ASSERT_TRUE(day6::bonus::is_marker({'a','b','c','d'}));
   ASSERT_FALSE(day6::bonus::is_marker({'a','b','c','c'}));
}

TEST(adventofcode2022_methods, day8_visibility)
{
   ASSERT_EQ(1, day8::visibility({0,0}, {{6,6,3,1}}, mzlib::direction::e));
   ASSERT_EQ(3, day8::visibility({0,0}, {{6,5,5,5}}, mzlib::direction::e));
   ASSERT_EQ(2, day8::visibility({0,0}, {{6,3,6,4}}, mzlib::direction::e));
   ASSERT_EQ(6, day8::visibility({0,0}, {{6,3,2,0,4,4,6}}, mzlib::direction::e));

}
/*
TEST(adventofcode2022_methods, day9_are_touching)
{
   mzlib::coordinates2d pos{1,1};

   ASSERT_TRUE(day9::are_touching({1,1}, {0,0}));
   ASSERT_TRUE(day9::are_touching({1,1}, {0,1}));
   ASSERT_TRUE(day9::are_touching({1,1}, {0,2}));
   ASSERT_TRUE(day9::are_touching({1,1}, {1,0}));
   ASSERT_TRUE(day9::are_touching({1,1}, {1,2}));
   ASSERT_TRUE(day9::are_touching({1,1}, {2,0}));
   ASSERT_TRUE(day9::are_touching({1,1}, {2,1}));
   ASSERT_TRUE(day9::are_touching({1,1}, {2,2}));

   ASSERT_FALSE(day9::are_touching({1,1}, {3,1}));
   ASSERT_FALSE(day9::are_touching({1,1}, {3,2}));
   ASSERT_FALSE(day9::are_touching({1,1}, {1,3}));
   ASSERT_FALSE(day9::are_touching({1,1}, {-1,3}));
   ASSERT_FALSE(day9::are_touching({1,1}, {1,-1}));
   ASSERT_FALSE(day9::are_touching({1,1}, {2,-1}));
}
*/
TEST(adventofcode2022_methods, day9_sample_input)
{
   std::vector<std::pair<char, int>> directions ={
      {'R', 4},
      {'U', 4},
      {'L', 3},
      {'D', 1},
      {'R', 4},
      {'D', 1},
      {'L', 5},
      {'R', 2}
   };
   auto v = day9::get_visited(directions, 2);

   ASSERT_EQ(13, v.size());
}


TEST(adventofcode2022_methods, day9_sample_input_2)
{
   std::vector<std::pair<char, int>> directions ={
      {'R', 5},
      {'U', 8},
      {'L', 8},
      {'D', 3},
      {'R', 17},
      {'D', 10},
      {'L', 25},
      {'U', 20}
   };
   auto v = day9::get_visited(directions, 10);

   ASSERT_EQ(36, v.size());
}

/*
 *       TEMPLATE
 */

/*
TEST(adventofcode2022_methods, dayX_method_name)
{
   ASSERT_EQ(VALUE, dayX::method_name());
}
*/
