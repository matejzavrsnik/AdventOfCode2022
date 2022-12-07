#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"

#include <string>
#include <utility>
#include <algorithm>
#include <ranges>

namespace adventofcode2022::day4
{

using assignment_pairs = std::pair<std::pair<int, int>, std::pair<int, int>>;

// utilities defined below solutions
assignment_pairs
convert (std::string s);

bool
one_inside_other (
   std::pair<int, int> one,
   std::pair<int, int> other
);

bool
is_fully_contained (assignment_pairs assignments);

bool
one_overlaps_other (
   std::pair<int, int> one,
   std::pair<int, int> other
);

bool
is_overlapping (assignment_pairs assignments);

// part 1 solution
inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<assignment_pairs> assignments;
   std::transform(
      input.begin(), input.end(), std::back_inserter(assignments), [] (auto s) { return convert(s); }
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
      input.begin(), input.end(), std::back_inserter(assignments), [] (auto s) { return convert(s); }
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
      mzlib::read_file_lines(input_file) | std::views::transform(convert) | std::views::filter(is_overlapping)
   );
}

}

// convert the line in file into pair of pairs. format: 41-42,40-40
inline assignment_pairs
convert (std::string s)
{
   auto elfs = mzlib::split(s, ",");
   auto assignment1 = mzlib::split(elfs[0], "-");
   auto assignment2 = mzlib::split(elfs[1], "-");

   return {{std::stoi(assignment1[0].data()), std::stoi(assignment1[1].data())},
      {std::stoi(assignment2[0].data()), std::stoi(assignment2[1].data())}};
}

inline bool
one_inside_other (
   std::pair<int, int> one,
   std::pair<int, int> other
)
{
   return one.first <= other.first && one.second >= other.second;
}

inline bool
is_fully_contained (assignment_pairs assignments)
{
   return one_inside_other(assignments.first, assignments.second)
      || one_inside_other(assignments.second, assignments.first);
}

inline bool
one_overlaps_other (
   std::pair<int, int> one,
   std::pair<int, int> other
)
{
   return one.second >= other.first && one.first <= other.second;
}

inline bool
is_overlapping (assignment_pairs assignments)
{
   return one_overlaps_other(assignments.first, assignments.second)
      || one_overlaps_other(assignments.second, assignments.first);
}

}