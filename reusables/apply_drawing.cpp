//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "apply_drawing.h"

TEST(reusables, apply_drawing)
{

   auto canvas = mnv::construct(40, 7, 0);

   const mzlib::grid::type<int> drawing = {
      {0,1,0},
      {1,1,1},
      {0,1,0},
   };

   apply_drawing(canvas, drawing, {2,7});

   ASSERT_EQ(std::vector<int>({0,0,0,0,0,0,0}), canvas[6]);
   ASSERT_EQ(std::vector<int>({0,0,0,1,0,0,0}), canvas[7]);
   ASSERT_EQ(std::vector<int>({0,0,1,1,1,0,0}), canvas[8]);
   ASSERT_EQ(std::vector<int>({0,0,0,1,0,0,0}), canvas[9]);
   ASSERT_EQ(std::vector<int>({0,0,0,0,0,0,0}), canvas[10]);
}
