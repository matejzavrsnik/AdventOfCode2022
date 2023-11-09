//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "move_cartesian.h"

TEST(reusables, move_cartesian)
{
   // 2 . . .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   mzlib::coordinates2d pos{1,1};

   // 2 . . .
   // 1 . o m
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({2,1}), move_cartesian(pos, mzlib::direction::e));

   // 2 . . .
   // 1 m o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({0,1}), move_cartesian(pos, mzlib::direction::w));

   // 2 . m .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({1,2}), move_cartesian(pos, mzlib::direction::n));

   // 2 . . .
   // 1 . o .
   // 0 . m .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({1,0}), move_cartesian(pos, mzlib::direction::s));

   // 2 . . m
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({2,2}), move_cartesian(pos, mzlib::direction::ne));

   // 2 m . .
   // 1 . o .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({0,2}), move_cartesian(pos, mzlib::direction::nw));

   // 2 . . .
   // 1 . o .
   // 0 . . m
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({2,0}), move_cartesian(pos, mzlib::direction::se));

   // 2 . . .
   // 1 . o .
   // 0 m . .
   //   0 1 2
   ASSERT_EQ(mzlib::coordinates2d({0,0}), move_cartesian(pos, mzlib::direction::sw));

   // 2 . . .
   // 1 . m .
   // 0 . . .
   //   0 1 2
   ASSERT_EQ(pos, move_cartesian(pos, mzlib::direction::centre));
}