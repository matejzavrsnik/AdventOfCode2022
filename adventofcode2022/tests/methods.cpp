#include <gtest/gtest.h>

#include "../puzzles/day6.h"
#include "../puzzles/day8.h"

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
 *       TEMPLATE
 */

/*
TEST(adventofcode2022_methods, dayX_method_name)
{
   ASSERT_EQ(VALUE, dayX::method_name());
}
*/
