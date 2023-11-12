//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "move_unless.h"
#include "grid/grid.h"

TEST(reusables, move_unless__by_one__right__can)
{
   mzlib::grid::type<long> grid = mzlib::grid::construct<long>(5, 8);
   mzlib::grid::type<long> grid_expected = mzlib::grid::construct<long>(5, 8);

   mzlib::grid::type<long> drawing = {
      {0,1,0},
      {1,1,1},
      {0,1,0},
   };

   apply_drawing(grid, drawing, {2,1});
   // 0 0 0 0 0 0 0 0
   // 0 0 0 1 0 0 0 0
   // 0 0 1 1 1 0 0 0
   // 0 0 0 1 0 0 0 0
   // 0 0 0 0 0 0 0 0

   apply_drawing(grid_expected, drawing, {3,1});
   // 0 0 0 0 0 0 0 0
   // 0 0 0 0 1 0 0 0
   // 0 0 0 1 1 1 0 0
   // 0 0 0 0 1 0 0 0
   // 0 0 0 0 0 0 0 0

   move_unless(grid, drawing, {2,1}, {3,1});

   ASSERT_EQ(grid, grid_expected);
}

TEST(reusables, move_unless__by_one__right__cannot)
{
   mzlib::grid::type<long> grid = mzlib::grid::construct<long>(5, 8);
   mzlib::grid::type<long> grid_expected = mzlib::grid::construct<long>(5, 8);

   mzlib::grid::type<long> drawing = {
      {0,1,0},
      {1,1,1},
      {0,1,0},
   };

   apply_drawing(grid, drawing, {2,1});
   // 0 0 0 0 0 0 0 0
   // 0 0 0 1 0 0 0 0
   // 0 0 1 1 1 0 0 0
   // 0 0 0 1 0 0 0 0
   // 0 0 0 0 0 0 0 0

   mzlib::grid::access(grid, {5,2}) = 1;
   // 0 0 0 0 0 0 0 0
   // 0 0 0 1 0 0 0 0
   // 0 0 1 1 1 1 0 0
   // 0 0 0 1 0 0 0 0
   // 0 0 0 0 0 0 0 0

   auto grid_before_move = grid;

   move_unless(grid, drawing, {2,1}, {3,1});

   ASSERT_EQ(grid, grid_before_move);
}