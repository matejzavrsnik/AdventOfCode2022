#include "puzzles/day1.h"

#include <iostream>

int
main ()
{
   std::cout
      << "Advent of Code, 2022" << std::endl
      << "====================" << std::endl
      << "Day 1: Calorie Counting" << std::endl
      << "  Elf carrying most calories: "
         << elf_with_most_calories("./res/day1_calories_per_elf.txt") << std::endl
      << "  Top three elves carry: "
         << top_three_elves_calories("./res/day1_calories_per_elf.txt") << std::endl;

   return 0;
}
