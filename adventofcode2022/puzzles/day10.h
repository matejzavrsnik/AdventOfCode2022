#pragma once

#include <numeric>
#include <ranges>
#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"

namespace adventofcode2022::day10
{

/*
 *                 METHOD DECLARATIONS
 */

inline int next_significant_tick(int after)
{
   if (after < 20) return 20;

   int factor = (after-20)/40 + 1;
   return 20 + factor * 40;
}

inline std::map<int, int>
get_significant_registry_changes (std::vector<std::pair<std::string_view, int>>& commands)
{
   int ticks_passed=0;
   int x_register=1;
   std::map<int, int> ticks_to_x;
   ticks_to_x[0] = 1;
   for(const auto& [command, operand] : commands)
   {
      int to_add = 0;
      if(command == "noop")
         ticks_passed += 1;
      else if (command == "addx")
      {
         ticks_passed += 2;
         to_add = operand;
      }
      else
         std::terminate();

      const int nst = next_significant_tick(ticks_to_x.rbegin()->first);
      if (ticks_passed > nst && !ticks_to_x.contains(nst))
      {
         ticks_to_x[nst] = x_register;
      }

      x_register += to_add;

   }
   return ticks_to_x;
}

inline std::vector<int>
get_registry_time_series (std::vector<std::pair<std::string_view, int>>& commands)
{
   std::vector<int> values;
   int reg_x=1;
   for(const auto& [command, operand] : commands)
   {
      if(command == "noop")
         values.push_back(reg_x);
      else if (command == "addx")
      {
         values.push_back(reg_x);
         values.push_back(reg_x);
         reg_x += operand;
      }
      else
         std::terminate();
   }
   return values;
}

/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<std::pair<std::string_view, int>> converted;
   mzlib::copy_modify(input, converted, [](const auto& e){
      auto s = mzlib::split(e, " ");
      if (s.size() > 1)
         return std::make_pair(s[0], std::stoi(s[1].data()));
      else
         return std::make_pair(s[0], 0);
   });

   std::map<int, int> ticks_to_x = get_significant_registry_changes(converted);

   int result = std::accumulate(ticks_to_x.begin(), ticks_to_x.end(), 0,
      [](auto sum, const auto& e){
         return sum += (e.first * e.second);
      });

   return result;
}

inline bool
is_pixel_lit (
   std::vector<int> ticks_to_x,
   int current_tick,
   int col
)
{
   return (ticks_to_x[current_tick]-1 <= col && col <= ticks_to_x[current_tick]+1);
}

inline std::vector<std::string>
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<std::pair<std::string_view, int>> converted;
   mzlib::copy_modify(input, converted, [](const auto& e){
      auto s = mzlib::split(e, " ");
      if (s.size() > 1)
         return std::make_pair(s[0], std::stoi(s[1].data()));
      else
         return std::make_pair(s[0], 0);
   });

   auto ticks_to_x = get_registry_time_series(converted);

   const int pixels_in_row = 40;
   const int row_count = 6;
   std::vector<std::string> screen;
   for(int row : std::views::iota(0, row_count))
   {
      screen.push_back("");
      for (int col: std::views::iota(0, pixels_in_row))
      {
         int tick = (row * pixels_in_row) + col;
         bool pixel_lit = is_pixel_lit(ticks_to_x, tick, col);
         screen.back() += (pixel_lit ? '#' : ' ');
      }
   }

   return screen;
}

/*
 *                 METHOD DEFINITIONS
 */


/*
 *                 EXTRA
 */

namespace bonus
{

}

}
