//
// Created by matej on 08/11/23.
//

#include <list>
#include <gtest/gtest.h>
#include "nature/vector.h"
#include "move_to_next_pixel.h"

TEST(reusables, iterate)
{
   mzlib::coordinates2d c{5,7};

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::coordinates2d({6,7}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::coordinates2d({7,7}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::coordinates2d({5,8}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::coordinates2d({6,8}), c);

   ASSERT_TRUE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::coordinates2d({7,8}), c);

   ASSERT_FALSE(move_to_next_pixel(c, {5,7}, {8,9}));
   ASSERT_EQ(mzlib::coordinates2d({7,8}), c);
}

