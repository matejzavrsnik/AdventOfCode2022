#include "puzzles/day1.h"
#include "puzzles/day2.h"

#include <iostream>

int
main ()
{
   std::cout
      << "Advent of Code, 2022" << std::endl
      << "====================" << std::endl
      << "Day 1: Calorie Counting" << std::endl
      << "  Elf carrying most calories: " << elf_with_most_calories("./res/day1_calories_per_elf.txt") << std::endl
      << "  Top three elves carry: " << top_three_elves_calories("./res/day1_calories_per_elf.txt") << std::endl
      << "Day 2: Rock Paper Scissors" << std::endl
      << "  I know what he meant, this is the score: " << score_strategy_guide("./res/day2_strategy_guide.txt") << std::endl
      << "  Well actually, now that the elf explained it: " << score_strategy_guide_proper("./res/day2_strategy_guide.txt") << std::endl
      << "  LOLz: " << lolz::score_strategy_guide_proper("./res/day2_strategy_guide.txt") << std::endl;

   return 0;
}
