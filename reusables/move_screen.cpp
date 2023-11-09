//
// Created by matej on 08/11/23.
//

#include <vector>
#include <list>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "grabbag.h"
#include "move_screen.h"

TEST(reusables, move_screen)
{
   //   0 1 2
   // 0 . . .
   // 1 . o .
   // 2 . . .
   mzlib::coordinates2d pos{1,1};

   //   0 1 2
   // 0 . . .
   // 1 . o m
   // 2 . . .
   ASSERT_EQ(mzlib::coordinates2d({2,1}), move_screen(pos, mzlib::direction::e));

   //   0 1 2
   // 0 . . .
   // 1 m o .
   // 2 . . .
   ASSERT_EQ(mzlib::coordinates2d({0,1}), move_screen(pos, mzlib::direction::w));

   //   0 1 2
   // 0 . m .
   // 1 . o .
   // 2 . . .
   ASSERT_EQ(mzlib::coordinates2d({1,0}), move_screen(pos, mzlib::direction::n));

   //   0 1 2
   // 0 . . .
   // 1 . o .
   // 2 . m .
   ASSERT_EQ(mzlib::coordinates2d({1,2}), move_screen(pos, mzlib::direction::s));

   //   0 1 2
   // 0 . . m
   // 1 . o .
   // 2 . . .
   ASSERT_EQ(mzlib::coordinates2d({2,0}), move_screen(pos, mzlib::direction::ne));

   //   0 1 2
   // 0 m . .
   // 1 . o .
   // 2 . . .
   ASSERT_EQ(mzlib::coordinates2d({0,0}), move_screen(pos, mzlib::direction::nw));

   //   0 1 2
   // 0 . . .
   // 1 . o .
   // 2 . . m
   ASSERT_EQ(mzlib::coordinates2d({2,2}), move_screen(pos, mzlib::direction::se));

   //   0 1 2
   // 0 . . .
   // 1 . o .
   // 2 m . .
   ASSERT_EQ(mzlib::coordinates2d({0,2}), move_screen(pos, mzlib::direction::sw));

   //   0 1 2
   // 0 . . .
   // 1 . m .
   // 2 . . .
   ASSERT_EQ(pos, move_screen(pos, mzlib::direction::centre));
}