//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "fits_on_grid.h"
#include "grid/grid.h"

TEST(reusables, fits_on_grid__does)
{
   mzlib::grid::type<long> grid = mzlib::grid::construct<long>(5, 8);

   mzlib::grid::type<long> drawing = {
      {0,1,0},
      {1,1,1},
      {0,1,0},
   };

   ASSERT_TRUE(fits_on_grid(grid, drawing, {5,2}));
   // 0 0 0 0 0 0 0 0
   // 0 0 0 0 0 0 0 0
   // 0 0 0 0 0 0 1 0
   // 0 0 0 0 0 1 1 1
   // 0 0 0 0 0 0 1 0
}

TEST(reusables, fits_on_grid__does_not)
{
   mzlib::grid::type<long> grid = mzlib::grid::construct<long>(5, 8);

   mzlib::grid::type<long> drawing = {
      {0,1,0},
      {1,1,1},
      {0,1,0},
   };

   ASSERT_FALSE(fits_on_grid(grid, drawing, {6,2}));
   // 0 0 0 0 0 0 0 0
   // 0 0 0 0 0 0 0 0
   // 0 0 0 0 0 0 0 1
   // 0 0 0 0 0 0 1 1 1
   // 0 0 0 0 0 0 0 1
}