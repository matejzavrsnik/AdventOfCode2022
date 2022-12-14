#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include <numeric>
#include <ranges>
#include <algorithm>
#include <deque>

namespace adventofcode2022::dayX
{

/*
 *                 METHOD DECLARATIONS
 */

/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   /*
   TYPE converted;
   mzlib::copy_modify(input, converted, [](const auto& e){
      return CONVERSION;
   });
    */

   return -1;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   /*
   TYPE converted;
   mzlib::copy_modify(input, converted, [](const auto& e){
      return CONVERSION;
   });
    */

   return -1;
}

/*
 *                 METHOD DEFINITIONS
 */


/*
 *                 EXTRA
 */

namespace bonus
{

}

}
