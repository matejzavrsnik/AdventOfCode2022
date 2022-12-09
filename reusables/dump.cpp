#include "dump.h"

#include "nature/vector.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
#include <vector>

TEST(reusables, dump_move_cartesian)
{
   mzlib::coordinates2d pos{1,1};

   ASSERT_EQ(2, move_cartesian(pos, mzlib::direction::e)[0]);
   ASSERT_EQ(1, move_cartesian(pos, mzlib::direction::e)[1]);

   ASSERT_EQ(0, move_cartesian(pos, mzlib::direction::w)[0]);
   ASSERT_EQ(1, move_cartesian(pos, mzlib::direction::w)[1]);

   ASSERT_EQ(1, move_cartesian(pos, mzlib::direction::n)[0]);
   ASSERT_EQ(2, move_cartesian(pos, mzlib::direction::n)[1]);

   ASSERT_EQ(1, move_cartesian(pos, mzlib::direction::s)[0]);
   ASSERT_EQ(0, move_cartesian(pos, mzlib::direction::s)[1]);


   ASSERT_EQ(2, move_cartesian(pos, mzlib::direction::ne)[0]);
   ASSERT_EQ(2, move_cartesian(pos, mzlib::direction::ne)[1]);

   ASSERT_EQ(0, move_cartesian(pos, mzlib::direction::nw)[0]);
   ASSERT_EQ(2, move_cartesian(pos, mzlib::direction::nw)[1]);

   ASSERT_EQ(2, move_cartesian(pos, mzlib::direction::se)[0]);
   ASSERT_EQ(0, move_cartesian(pos, mzlib::direction::se)[1]);

   ASSERT_EQ(0, move_cartesian(pos, mzlib::direction::sw)[0]);
   ASSERT_EQ(0, move_cartesian(pos, mzlib::direction::sw)[1]);

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

   ASSERT_FALSE(are_touching(pos, {3,1}));
   ASSERT_FALSE(are_touching(pos, {3,2}));
   ASSERT_FALSE(are_touching(pos, {1,3}));
   ASSERT_FALSE(are_touching(pos, {-1,3}));
   ASSERT_FALSE(are_touching(pos, {1,-1}));
   ASSERT_FALSE(are_touching(pos, {2,-1}));
}