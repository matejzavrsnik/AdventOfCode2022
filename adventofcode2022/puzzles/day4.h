#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"

#include <string>
#include <utility>
#include <algorithm>
#include <ranges>

#include "../../reusables/parse_pairs_of_numbers.h"

namespace adventofcode2022::day4
{

template<typename T>
bool
intervals_overlapping (
   const std::pair<T, T>& one,
   const std::pair<T, T>& other
)
{
   return one.second >= other.first && one.first <= other.second;
}

template<typename T>
bool
intervals_overlap (
   const std::pair<T, T>& a,
   const std::pair<T, T>& b)
{
   return intervals_overlapping(a, b)
      || intervals_overlapping(b, a);
}

using assignment_pairs = std::pair<std::pair<int, int>, std::pair<int, int>>;
inline bool
is_overlapping (assignment_pairs assignments)
{
   //return interval_overlaps_the_other(assignments.first, assignments.second)
   //   || interval_overlaps_the_other(assignments.second, assignments.first);
   return intervals_overlap(assignments.first, assignments.second);
}

template<typename T>
bool
interval_inside_the_other (
   const std::pair<T, T>& one,
   const std::pair<T, T>& other
)
{
   return one.first <= other.first && one.second >= other.second;
}

template<typename T>
bool
intervals_fully_contained (
   const std::pair<T, T>& a,
   const std::pair<T, T>& b)
{
   return interval_inside_the_other(a, b)
      || interval_inside_the_other(b, a);
}

inline bool
is_fully_contained (assignment_pairs assignments)
{
   //return is_in(assignments.first, assignments.second)
   //   || is_in(assignments.second, assignments.first);
   return intervals_fully_contained(assignments.first, assignments.second);
}

// part 1 solution
inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<assignment_pairs> assignments;
   std::transform(
      input.begin(), input.end(), std::back_inserter(assignments), [] (auto s) { return parse_pairs_of_numbers(s); }
   );

   int count = std::count_if(
      assignments.begin(), assignments.end(), [] (auto a) { return is_fully_contained(a); }
   );

   return count;
}

// part 2 solution
inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<assignment_pairs> assignments;
   std::transform(
      input.begin(), input.end(), std::back_inserter(assignments), [] (auto s) { return parse_pairs_of_numbers(s); }
   );

   int count = std::count_if(
      assignments.begin(), assignments.end(), [] (auto a) { return is_overlapping(a); }
   );

   return count;
}

namespace bonus
{

// try ranges
inline long
part2 (std::string input_file)
{
   return std::ranges::distance(
      mzlib::read_file_lines(input_file) | std::views::transform(parse_pairs_of_numbers) | std::views::filter(is_overlapping)
   );
}

}





}