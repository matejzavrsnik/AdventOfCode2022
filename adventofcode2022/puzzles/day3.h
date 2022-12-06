#pragma once

#include "../../reusables/sets_intersection_plural.h"
#include "filesystem/read_write_file.h"
#include <numeric>
#include <set>
#include <algorithm>
#include <span>

namespace adventofcode2022::day3
{

long
prioritise (char item)
{
   // Lowercase item types a through z have priorities 1 through 26.
   // Uppercase item types A through Z have priorities 27 through 52.
   if (item >= 'a' && item <= 'z')
      return item - 'a' + 1;
   if (item >= 'A' && item <= 'Z')
      return item - 'A' + 27;
   std::terminate();
}

// my first attempt that worked; see below for refactor
long
part1 (std::string input_file)
{
   auto rucksacks_content = mzlib::read_file_lines(input_file);

   long sum_priority = std::accumulate(
      rucksacks_content.begin(), rucksacks_content.end(), 0, [] (
         auto priority,
         const auto& contents
      )
      {
         const auto& contents_middle = contents.begin() + contents.size() / 2;
         std::set<char> first_compartment{contents.begin(), contents_middle};
         std::set<char> already_prioritised;
         std::for_each(
            contents_middle, contents.end(), [&first_compartment, &priority, &already_prioritised] (const auto& item)
            {
               if (first_compartment.contains(item) && !already_prioritised.contains(item))
               {
                  priority += prioritise(item);
                  already_prioritised.insert(item);
               }
            }
         );
         return priority;
      }
   );

   return sum_priority;
}

// my first attempt
long
part2 (std::string input_file)
{
   auto rucksacks_content = mzlib::read_file_lines(input_file);

   long priorities = 0;
   for (auto first_in_group_it = rucksacks_content.begin();
      first_in_group_it != rucksacks_content.end();
      first_in_group_it += 3)
   {
      // look, it works, ok? :)
      auto elf1 = *(first_in_group_it);
      auto elf2 = *(first_in_group_it + 1);
      auto elf3 = *(first_in_group_it + 2);
      std::sort(elf1.begin(), elf1.end());
      std::sort(elf2.begin(), elf2.end());
      std::sort(elf3.begin(), elf3.end());
      std::vector<char> possible_badges;
      std::set_intersection(
         elf1.begin(), elf1.end(), elf2.begin(), elf2.end(), std::back_inserter(possible_badges)
      );
      std::vector<char> hopefully_one_badge;
      std::set_intersection(
         possible_badges.begin(), possible_badges.end(), elf3.begin(), elf3.end(),
         std::back_inserter(hopefully_one_badge)
      );
      if (hopefully_one_badge.size() != 1)
         std::terminate();
      priorities += prioritise(hopefully_one_badge[0]);
   }

   return priorities;
}

namespace bonus
{

// refactored version
long
part2 (std::string input_file)
{
   auto rucksacks_content = mzlib::read_file_lines(input_file);

   std::string all_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   std::sort(all_letters.begin(), all_letters.end()); // in case I didn't order them correctly

   auto first_elf_it = rucksacks_content.begin();
   decltype(first_elf_it) elf_it;

   long priorities = 0;
   do
   {
      std::string possible_badges = all_letters;
      elf_it = first_elf_it;
      do
      {
         std::string new_possible_badges;
         std::sort(elf_it->begin(), elf_it->end());
         std::set_intersection(
            possible_badges.begin(), possible_badges.end(), elf_it->begin(), elf_it->end(),
            std::back_inserter(new_possible_badges)
         );
         std::swap(possible_badges, new_possible_badges);
         ++elf_it;
      }
      while (elf_it - first_elf_it < 3 && elf_it != rucksacks_content.end());
      first_elf_it = elf_it;
      priorities += prioritise(possible_badges[0]);
   }
   while (first_elf_it != rucksacks_content.end());

   return priorities;
}

// not sure why it didn't occur to me earlier that this is an operation over sets
long
part1 (std::string input_file)
{
   auto rucksacks_content = mzlib::read_file_lines(input_file);

   return std::accumulate(
      rucksacks_content.begin(), rucksacks_content.end(), 0, [] (
         auto priority,
         auto& contents
      )
      {
         const auto contents_middle = contents.begin() + contents.size() / 2;
         // sort each half separately, in place, so that set operation can work
         std::sort(contents.begin(), contents_middle);
         std::sort(contents_middle, contents.end());
         // get intersection
         std::set<char> intersection;
         std::set_intersection(
            contents.begin(), contents_middle, contents_middle, contents.end(),
            std::inserter(intersection, intersection.end())
         );
         // each set intersection item is in both compartments, as per definition
         for (auto item: intersection)
            priority += prioritise(item); // calc priority
         return priority;
      }
   );
}

}

}