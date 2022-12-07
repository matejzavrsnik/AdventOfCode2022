#include <gtest/gtest.h>

#include "../puzzles/day6.h"

using namespace adventofcode2022;

TEST(adventofcode2022_methods, day6_is_marker)
{
   ASSERT_TRUE(day6::bonus::is_marker({'a','b','c','d'}));
   ASSERT_FALSE(day6::bonus::is_marker({'a','b','c','c'}));
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
