#include "puzzles/day1.h"

#include <iostream>

int
main ()
{
   std::cout << "Advent of Code, 2022" << std::endl;
   std::cout << "====================" << std::endl;
   std::cout << "Day 1: Calorie Counting" << std::endl;
   std::cout << "  Elf carrying most calries: " << elf_with_most_calories("./res/calories_per_elf.txt") << std::endl;
   std::cout << "  Top three elves carry: " << top_three_elves_calories("./res/calories_per_elf.txt") << std::endl;
   return 0;
}
