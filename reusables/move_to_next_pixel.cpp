//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "move_to_next_pixel.h"

TEST(reusables, iterate)
{
   mzlib::grid::cell c{5,7};

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::grid::cell({6,7}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::grid::cell({7,7}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::grid::cell({5,8}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::grid::cell({6,8}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::grid::cell({7,8}), c);

   ASSERT_FALSE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::grid::cell({7,8}), c);
}

