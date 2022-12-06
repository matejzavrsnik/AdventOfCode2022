#include "run.h"

#include "puzzles/day1.h"
#include "puzzles/day2.h"
#include "puzzles/day3.h"
#include "puzzles/day4.h"
#include "puzzles/day5.h"
#include "puzzles/day6.h"
#include "puzzles/day7.h"

#include <iostream>

void adventofcode2021::run ()
{
   std::cout
      << "Advent of Code, 2021" << std::endl
      << "====================" << std::endl
      << "Day 1: " << std::endl
      << "  Part 1: " << adventofcode2021::day1::part1("./res/adventofcode2021/day1.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day1::part2("./res/adventofcode2021/day1.txt") << std::endl
      << "Day 2: " << std::endl
      << "  Part 1: " << adventofcode2021::day2::part1("./res/adventofcode2021/day2.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day2::part2("./res/adventofcode2021/day2.txt") << std::endl
      << "Day 3: " << std::endl
      << "  Part 1: " << adventofcode2021::day3::part1("./res/adventofcode2021/day3.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day3::part2("./res/adventofcode2021/day3.txt") << std::endl
      << "Day 4: " << std::endl
      << "  Part 1: " << adventofcode2021::day4::part1("./res/adventofcode2021/day4.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day4::part2("./res/adventofcode2021/day4.txt") << std::endl
      << "Day 5: " << std::endl
      << "  Part 1: " << adventofcode2021::day5::part1("./res/adventofcode2021/day5.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day5::part2("./res/adventofcode2021/day5.txt") << std::endl
      << "Day 6: " << std::endl
      << "  Part 1: " << adventofcode2021::day6::part1("./res/adventofcode2021/day6.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day6::part2("./res/adventofcode2021/day6.txt") << std::endl
      << "Day 7: " << std::endl
      << "  Part 1: " << adventofcode2021::day7::part1("./res/adventofcode2021/day7.txt") << std::endl
      << "  Part 2: " << adventofcode2021::day7::part2("./res/adventofcode2021/day7.txt") << std::endl;
};