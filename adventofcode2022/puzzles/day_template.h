#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "../../reusables/grabbag.h"

using namespace std;

namespace adventofcode2022::dayX
{

/*
 *                 METHODS
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

}