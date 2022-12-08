#include "move_vector.h"

#include <nature/vector.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(reusables, move_vector)
{
   mzlib::coordinates2d pos{1,1};

   ASSERT_EQ(1, move(pos, mzlib::direction::e)[0]);
   ASSERT_EQ(2, move(pos, mzlib::direction::e)[1]);

   ASSERT_EQ(1, move(pos, mzlib::direction::w)[0]);
   ASSERT_EQ(0, move(pos, mzlib::direction::w)[1]);

   ASSERT_EQ(0, move(pos, mzlib::direction::n)[0]);
   ASSERT_EQ(1, move(pos, mzlib::direction::n)[1]);

   ASSERT_EQ(2, move(pos, mzlib::direction::s)[0]);
   ASSERT_EQ(1, move(pos, mzlib::direction::s)[1]);
}