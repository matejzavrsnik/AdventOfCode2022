#include "puzzles/day1.h"
#include "puzzles/day2.h"
#include "puzzles/day3.h"

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
      << "  Bonus: " << bonus::score_strategy_guide_proper("./res/day2_strategy_guide.txt") << std::endl
      << "  Bonus 2: " << bonus::score_strategy_guide_proper2("./res/day2_strategy_guide.txt") << std::endl
      << "Day 3: Rucksack Reorganization" << std::endl
      << "  Prioritise rearrangements: " << prioritise_rearrangement("./res/day3_rucksack_items.txt") << std::endl
      << "  Find badges: " << find_badges("./res/day3_rucksack_items.txt") << std::endl
      << "  Bonus: " << bonus::prioritise_rearrangement("./res/day3_rucksack_items.txt") << std::endl
      << "  Bonus 2: " << bonus::find_badges("./res/day3_rucksack_items.txt") << std::endl;

   return 0;
}
