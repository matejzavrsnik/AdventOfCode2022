#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "../../reusables/grabbag.h"

using namespace std;

namespace adventofcode2022::day14
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

   vector<vector<mzlib::coordinates2d>> converted;
   mzlib::copy_modify(input, converted, [](const auto& e){
      auto numbers = mzlib::split(e, " ->,");
      vector<mzlib::coordinates2d> v;
      for(int n=0; n<numbers.size(); n+=2)
         v.push_back({stoi(numbers[n].data()), stoi(numbers[n+1].data())});
      return v;
   });


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