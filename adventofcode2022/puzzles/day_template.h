#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"

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

   std::vector<std::pair<char, int>> TARGET;
   mzlib::copy_modify(input, TARGET, [](auto e){
      auto s = mzlib::split(e, " ");
      return std::make_pair(s[0][0], std::stoi(s[1].data()));
   });

   return -1;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<std::pair<char, int>> TARGET;
   mzlib::copy_modify(input, TARGET, [](auto e){
      auto s = mzlib::split(e, " ");
      return std::make_pair(s[0][0], std::stoi(s[1].data()));
   });

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
