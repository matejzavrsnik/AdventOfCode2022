//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "move_cartesian.h"
#include "grid/grid.h"

TEST(reusables, move_cartesian)
{
   // 2 . . .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   mzlib::grid::cell pos{1,1};

   // 2 . . .
   // 1 . o m
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({2,1}), move_cartesian(pos, mzlib::direction::e));

   // 2 . . .
   // 1 m o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({0,1}), move_cartesian(pos, mzlib::direction::w));

   // 2 . m .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({1,2}), move_cartesian(pos, mzlib::direction::n));

   // 2 . . .
   // 1 . o .
   // 0 . m .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({1,0}), move_cartesian(pos, mzlib::direction::s));

   // 2 . . m
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({2,2}), move_cartesian(pos, mzlib::direction::ne));

   // 2 m . .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({0,2}), move_cartesian(pos, mzlib::direction::nw));

   // 2 . . .
   // 1 . o .
   // 0 . . m
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({2,0}), move_cartesian(pos, mzlib::direction::se));

   // 2 . . .
   // 1 . o .
   // 0 m . .
   //   0 1 2
   ASSERT_EQ(mzlib::grid::cell({0,0}), move_cartesian(pos, mzlib::direction::sw));

   // 2 . . .
   // 1 . m .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(pos, move_cartesian(pos, mzlib::direction::centre));
}