#include "grabbag.h"

#include "nature/vector.h"
#include "move_cartesian.h"
#include "get_direction_cartesian.h"
#include "are_touching.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
#include <vector>

TEST(reusables, are_touching)
{
   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   mzlib::coordinates2d pos{1,1};

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . m . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {0,0}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . m o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {0,1}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . m . . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {0,2}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . m . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {1,0}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . m . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {1,2}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . m .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {2,0}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o m .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {2,1}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . m .
   //  3 . . . . .
   ASSERT_TRUE(are_touching(pos, {2,2}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 m . . . .
   ASSERT_FALSE(are_touching(pos, {-1,3}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . m . . .
   ASSERT_FALSE(are_touching(pos, {0,3}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . m . .
   ASSERT_FALSE(are_touching(pos, {1,3}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . m .
   ASSERT_FALSE(are_touching(pos, {2,3}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . m
   ASSERT_FALSE(are_touching(pos, {3,3}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 m . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {-1,2}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . m
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {3,2}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 m . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {-1,1}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . .
   //  1 . . o . m
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {3,1}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 m . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {-1,0}));

   //   -1 0 1 2 3
   // -1 . . . . .
   //  0 . . . . m
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {3,0}));

   //   -1 0 1 2 3
   // -1 m . . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {-1,-1}));

   //   -1 0 1 2 3
   // -1 . m . . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {0,-1}));

   //   -1 0 1 2 3
   // -1 . . m . .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {1,-1}));

   //   -1 0 1 2 3
   // -1 . . . m .
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {2,-1}));

   //   -1 0 1 2 3
   // -1 . . . . m
   //  0 . . . . .
   //  1 . . o . .
   //  2 . . . . .
   //  3 . . . . .
   ASSERT_FALSE(are_touching(pos, {3,-1}));
}