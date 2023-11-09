//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "get_direction_cartesian.h"

TEST(reusables, get_direction_cartesian)
{
   // 2 . . .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   mzlib::coordinates2d pos{1,1};

   // 2 . . .
   // 1 m o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::w, get_direction_cartesian(pos, {0, 1}));

   // 2 . . .
   // 1 . o m
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::e, get_direction_cartesian(pos, {2, 1}));

   // 2 . m .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::n, get_direction_cartesian(pos, {1, 2}));

   // 2 . . .
   // 1 . o .
   // 0 . m .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::s, get_direction_cartesian(pos, {1, 0}));

   // 2 . . .
   // 1 . o .
   // 0 m . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::sw, get_direction_cartesian(pos, {0, 0}));

   // 2 m . .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::nw, get_direction_cartesian(pos, {0, 2}));

   // 2 . . .
   // 1 . o .
   // 0 . . m
   //   0 1 2
   ASSERT_EQ(mzlib::direction::se, get_direction_cartesian(pos, {2, 0}));

   // 2 . . m
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::ne, get_direction_cartesian(pos, {2, 2}));

   // 2 . . .
   // 1 . m .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::direction::centre, get_direction_cartesian(pos, {1, 1}));
}