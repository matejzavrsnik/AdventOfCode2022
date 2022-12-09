#include "grabbag.h"

#include "nature/vector.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
#include <vector>

TEST(reusables, dump_move_cartesian)
{
   mzlib::coordinates2d pos{1,1};
   ASSERT_EQ(mzlib::coordinates2d({2,1}), move_cartesian(pos, mzlib::direction::e));
   ASSERT_EQ(mzlib::coordinates2d({0,1}), move_cartesian(pos, mzlib::direction::w));
   ASSERT_EQ(mzlib::coordinates2d({1,2}), move_cartesian(pos, mzlib::direction::n));
   ASSERT_EQ(mzlib::coordinates2d({1,0}), move_cartesian(pos, mzlib::direction::s));
   ASSERT_EQ(mzlib::coordinates2d({2,2}), move_cartesian(pos, mzlib::direction::ne));
   ASSERT_EQ(mzlib::coordinates2d({0,2}), move_cartesian(pos, mzlib::direction::nw));
   ASSERT_EQ(mzlib::coordinates2d({2,0}), move_cartesian(pos, mzlib::direction::se));
   ASSERT_EQ(mzlib::coordinates2d({0,0}), move_cartesian(pos, mzlib::direction::sw));

   ASSERT_EQ(pos, move_cartesian(pos, mzlib::direction::centre));
}

TEST(adventofcode2022_methods, day9_get_direction_cartesian)
{
   mzlib::coordinates2d pos{1,1};

   ASSERT_EQ(mzlib::direction::centre, get_direction_cartesian(pos, {1, 1}));

   ASSERT_EQ(mzlib::direction::w, get_direction_cartesian(pos, {0, 1}));
   ASSERT_EQ(mzlib::direction::e, get_direction_cartesian(pos, {2, 1}));
   ASSERT_EQ(mzlib::direction::n, get_direction_cartesian(pos, {1, 2}));
   ASSERT_EQ(mzlib::direction::s, get_direction_cartesian(pos, {1, 0}));

   ASSERT_EQ(mzlib::direction::sw, get_direction_cartesian(pos, {0, 0}));
   ASSERT_EQ(mzlib::direction::nw, get_direction_cartesian(pos, {0, 2}));
   ASSERT_EQ(mzlib::direction::se, get_direction_cartesian(pos, {2, 0}));
   ASSERT_EQ(mzlib::direction::ne, get_direction_cartesian(pos, {2, 2}));
}

TEST(adventofcode2022_methods, day9_are_touching)
{
   mzlib::coordinates2d pos{1,1};

   ASSERT_TRUE(are_touching(pos, {0,0}));
   ASSERT_TRUE(are_touching(pos, {0,1}));
   ASSERT_TRUE(are_touching(pos, {0,2}));
   ASSERT_TRUE(are_touching(pos, {1,0}));
   ASSERT_TRUE(are_touching(pos, {1,2}));
   ASSERT_TRUE(are_touching(pos, {2,0}));
   ASSERT_TRUE(are_touching(pos, {2,1}));
   ASSERT_TRUE(are_touching(pos, {2,2}));

   ASSERT_FALSE(are_touching(pos, {-1,3}));
   ASSERT_FALSE(are_touching(pos, {0,3}));
   ASSERT_FALSE(are_touching(pos, {1,3}));
   ASSERT_FALSE(are_touching(pos, {2,3}));
   ASSERT_FALSE(are_touching(pos, {3,3}));

   ASSERT_FALSE(are_touching(pos, {-1,2}));
   ASSERT_FALSE(are_touching(pos, {3,2}));

   ASSERT_FALSE(are_touching(pos, {-1,1}));
   ASSERT_FALSE(are_touching(pos, {3,1}));

   ASSERT_FALSE(are_touching(pos, {-1,0}));
   ASSERT_FALSE(are_touching(pos, {3,0}));

   ASSERT_FALSE(are_touching(pos, {-1,-1}));
   ASSERT_FALSE(are_touching(pos, {0,-1}));
   ASSERT_FALSE(are_touching(pos, {1,-1}));
   ASSERT_FALSE(are_touching(pos, {2,-1}));
   ASSERT_FALSE(are_touching(pos, {3,-1}));
}