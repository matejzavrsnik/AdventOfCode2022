#pragma once

#include "filesystem/read_write_file.h"
#include <set>

namespace adventofcode2022::day6
{

// part 1 solution
long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   const auto window_size = 4;
   auto cursor = input.begin() + window_size - 1;
   std::set<char> window;
   do
   {
      window.clear();
      auto window_end = ++cursor;
      auto window_start = cursor - window_size;
      window.insert(window_start, window_end);
   }
   while (window.size() < window_size);

   return std::distance(input.begin(), cursor);
}

// part 2 solution
long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   const auto window_size = 14;
   auto cursor = input.begin() + window_size - 1;
   std::set<char> window;
   do
   {
      window.clear();
      auto window_end = ++cursor;
      auto window_start = cursor - window_size;
      window.insert(window_start, window_end);
   }
   while (window.size() < window_size);

   return std::distance(input.begin(), cursor);
}

namespace bonus
{

template <class Type>
void
remove_just_one (
   std::multiset<Type>& window,
   const Type& element
)
{
   const auto found = std::find(window.begin(), window.end(), element);
   if (found != window.end())
      window.erase(found);
}

bool
is_marker (const std::multiset<char>& window)
{
   return std::adjacent_find(
      window.begin(), window.end(), [] (
         auto a,
         auto b
      ) { return a == b; }
   ) == window.end();
}

// what bothered me with my original solution was that I created a new set for every window attempt.
// multiset::erase erases all elements that are equal to argument and I just wanted one to be deleted to make it a
// running window.
// rewrote so that I now find first such element in set and then delete it through an iterator.
// Price: O(m) to iterate signal * O(n+2*logn)) to search&insert&remove + 1 instantiation of set
// Price before: O(m) * O(nlogn) to insert all window chars + m instantiations of set.
// So for larger windows this version should be faster unless searching is way slower than inserting, but I don't see
// why it would be since to insert into a set it needs to search first.
long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   const auto window_size = 4;
   auto cursor = input.begin() + window_size;
   std::multiset<char> window(input.begin(), cursor);
   while (!is_marker(window) && cursor != input.end())
   {
      remove_just_one(window, *(cursor - window_size));
      window.insert(*++cursor);
   }

   return std::distance(input.begin(), cursor);
}

}

}