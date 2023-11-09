#include "grabbag.h"

#include "binary_string_to_int.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


TEST(reusables, binary_string_to_int)
{
   ASSERT_EQ(0, binary_string_to_int("000"));
   ASSERT_EQ(1, binary_string_to_int("001"));
   ASSERT_EQ(2, binary_string_to_int("010"));
   ASSERT_EQ(3, binary_string_to_int("011"));
   ASSERT_EQ(255, binary_string_to_int("11111111"));
}