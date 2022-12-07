#pragma once

#include "filesystem/read_write_file.h"
#include <algorithm>
#include <ranges>
#include <numeric>

namespace adventofcode2021::day1
{

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   long count=0;
   std::adjacent_find(input.begin(), input.end(),
      [&count](auto p, auto n){
         const int ip = std::stoi(p);
         const int in = std::stoi(n);
         if(in > ip)
            ++count;
         return false;
      });

   return count;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<int> measurements;
   std::transform(input.begin(), input.end(), std::back_inserter(measurements),
      [](auto in){ return std::stoi(in.data()); });

   const int window_size=3;
   auto window_start = measurements.begin();
   while(window_start+window_size-1 != measurements.end())
   {
      *window_start = std::accumulate(window_start, window_start + window_size, 0);
      ++window_start;
   }

   std::adjacent_difference(measurements.begin(), measurements.end(), measurements.begin());

   return std::count_if(measurements.begin()+1, measurements.end()-window_size+1,
      [](auto m){
      return m>0;
   });
}

namespace bonus
{

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   return 0;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   return 0;
}

}

}