#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"

#include <algorithm>
#include <ranges>
#include <string>

namespace adventofcode2022::day5
{

// utilities defined below solutions
struct step
{
   int move, from, to;
};

std::vector<std::vector<char>>
read_crate_stacks (const std::vector<std::string>& input);

std::vector<step>
read_steps (const std::vector<std::string> input);

void
use_cratemover9000 (
   const step one_step,
   std::vector<std::vector<char>>& crate_stacks
);

void
use_cratemover9001 (
   const step one_step,
   std::vector<std::vector<char>>& crate_stacks
);

std::string
get_top_crates (std::vector<std::vector<char>> crate_stacks);

// part 1 solution
inline std::string
part1 (std::string input_file)
{
   const auto input = mzlib::read_file_lines(input_file);

   auto crate_stacks = read_crate_stacks(input);
   auto steps_plan = read_steps(input);

   for (auto& step: steps_plan)
      use_cratemover9000(step, crate_stacks);

   std::string top_crates = get_top_crates(crate_stacks);
   return top_crates;
}

// part 2 solution
inline std::string
part2 (std::string input_file)
{
   const auto input = mzlib::read_file_lines(input_file);

   auto crate_stacks = read_crate_stacks(input);
   auto steps_plan = read_steps(input);

   for (auto& step: steps_plan)
      use_cratemover9001(step, crate_stacks);

   std::string top_crates = get_top_crates(crate_stacks);
   return top_crates;
}

inline std::vector<std::vector<char>>
read_crate_stacks (const std::vector<std::string>& input)
{
   std::vector<std::vector<char>> crate_stacks;

   // find empty line; that separates crate stacks from moves list
   auto it_delimiter_line = std::ranges::find_if(input, [] (auto line) { return line.empty(); });
   // stack numbers are one line above
   auto idx_stack_numbers_line = std::distance(input.begin(), it_delimiter_line - 1);
   // the rest of the lines above are marked crates, at the same location as the number, if they exist
   for (auto pos = 0; pos < input[idx_stack_numbers_line].length(); ++pos)
      if (std::isdigit(input[idx_stack_numbers_line][pos]))
      {
         std::vector<char> new_stack;
         for (auto crate_line = idx_stack_numbers_line - 1; crate_line >= 0; --crate_line)
            if (input[crate_line].length() > pos && std::isalpha(input[crate_line][pos]))
               new_stack.push_back(input[crate_line][pos]);
         crate_stacks.emplace_back(new_stack);
      }

   return crate_stacks;
}

inline std::vector<step>
read_steps (const std::vector<std::string> input)
{
   std::vector<step> steps;

   // find empty line; that separates crate stacks from moves list
   auto it_delimiter_line = std::ranges::find_if(input, [] (auto line) { return line.empty(); });
   // moves are all the lines after
   ++it_delimiter_line;
   std::for_each(
      it_delimiter_line, input.end(), [&steps] (auto line)
      {
         auto splits = mzlib::split(line, " ");
         steps.emplace_back(
            step{.move = std::stoi(splits[1].data()), .from = std::stoi(splits[3].data()), .to = std::stoi(
               splits[5].data()
            )}
         );
      }
   );

   return steps;
}

inline void
use_cratemover9000 (
   const step one_step,
   std::vector<std::vector<char>>& crate_stacks
)
{
   auto& from_stack = crate_stacks[one_step.from - 1];
   auto& to_stack = crate_stacks[one_step.to - 1];
   for (auto count = one_step.move; count > 0; --count)
   {
      if (from_stack.empty() || !std::isalpha(from_stack.back()))
         std::cout << "ERROR! WOOP WOOP! ERROR!" << std::endl;
      to_stack.push_back(from_stack.back());
      from_stack.pop_back();
   }
}

inline void
use_cratemover9001 (
   const step one_step,
   std::vector<std::vector<char>>& crate_stacks
)
{
   auto& from_stack = crate_stacks[one_step.from - 1];
   auto& to_stack = crate_stacks[one_step.to - 1];

   for (auto count = one_step.move; count > 0; --count)
      to_stack.push_back(from_stack[from_stack.size() - count]);

   for (auto count = one_step.move; count > 0; --count)
      from_stack.pop_back();
}

inline std::string
get_top_crates (std::vector<std::vector<char>> crate_stacks)
{
   std::string s;
   std::for_each(
      crate_stacks.begin(), crate_stacks.end(), [&s] (auto& crate_stack)
      {
         s.push_back(crate_stack.back());
      }
   );
   return s;
}

namespace bonus
{


}

}