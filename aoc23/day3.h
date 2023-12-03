#pragma once

#include "everything_bagel.h"

namespace aoc23::d3
{

inline pair<optional<ll>, cell>
read_number_starting_here (
   const gridt<char>& engine,
   cell c
)
{
   string number;
   while(grid::is_in(engine, c)
      && isdigit(grid::access(engine, c)))
   {
      number += grid::access(engine, c);
      c = grid::move_cartesian(c, direction::e);
   }
   auto result_number = number.empty() ? nullopt : optional(stoll(number));
   auto last_cell = grid::move_cartesian(c, direction::w);
   return {result_number, last_cell};
}

set<cell>
get_all_cells_for_number (
   const gridt<char>& engine,
   cell c
)
{
   set<cell> cells_for_number;
   while(grid::is_in(engine, c)
      && isdigit(grid::access(engine, c)))
   {
      cells_for_number.insert(c);
      c = grid::move_cartesian(c, direction::e);
   }
   return cells_for_number;
}

set<cell>
get_all_neighbours (
   const gridt<char>& engine,
   const set<cell>& cells
)
{
   set<cell> neighbours;
   for(auto c : cells)
      for(auto neighbour : grid::get_neighbouring_cells_star(engine, c))
         if (!cells.contains(neighbour)) // it's not a neighbour if it's original cell
            neighbours.insert(neighbour);

   return neighbours;
}

template<typename Criterium>
bool
is_symbol_adjacent (
   const gridt<char>& engine,
   cell c,
   Criterium symbol_definition
)
{
   using namespace std::placeholders;
   auto number_cells = get_all_cells_for_number(engine, c);
   auto neighbours = get_all_neighbours(engine, number_cells);

   return absl::c_any_of(neighbours, [&](cell c) { return symbol_definition(engine, c); });
}

template<typename CriteriumEvalFunction>
set<cell>
get_adjacent_cells_like (
   const gridt<char>& engine,
   cell c,
   CriteriumEvalFunction symbol_definition
)
{
   auto number_cells = get_all_cells_for_number(engine, c);
   auto neighbours = get_all_neighbours(engine, number_cells);

   return neighbours
      | ranges::views::filter([&](cell c) { return symbol_definition(engine, c); })
      | ranges::to<set<cell>>();
}

inline ll
p1 (vec<string> input)
{
   // convert to my grid
   const gridt<char> engine = grid::convert_to_grid<char>(input);
   const cell first_cell{0,0};
   const cell last_cell{static_cast<long>(grid::height(engine)), static_cast<long>(grid::width(engine))};

   // for each cell in grid
   cell c = first_cell;
   ll result_sum = 0;
   do {
      // try read number
      auto [number, last_num_cell] = read_number_starting_here(engine, c);
      // if there is number here
      if(number.has_value())
      {
         auto symbol_definition = [](const gridt<char>& engine, cell c) {
            auto cell_value = grid::access(engine, c);
            return !isdigit(cell_value) && cell_value!='.';
         };
         bool symbol_adjacent = is_symbol_adjacent(engine, c, symbol_definition);
         if (symbol_adjacent)
         {
            result_sum += number.value();
         }
         c = last_num_cell;
      }
   }
   while(grid::move_to_next_cell(c, first_cell, last_cell));

   return result_sum;
}

inline ll
p2 (vec<string> input)
{
   // convert to my grid
   const gridt<char> engine = grid::convert_to_grid<char>(input);
   const cell first_cell{0,0};
   const cell last_cell{static_cast<long>(grid::height(engine)), static_cast<long>(grid::width(engine))};

   // for each cell in grid
   cell c = first_cell;
   map<cell /*gear*/, set<ll> /*adjacent numbers*/> gears_to_numbers;
   do {
      // try read number
      auto [number, last_num_cell] = read_number_starting_here(engine, c);
      // if there is number here
      if(number.has_value())
      {
         auto gear_definition = [](const gridt<char>& engine, cell c) {
            return grid::access(engine, c)=='*';
         };
         // get all neighbour cells that are gears
         auto adjacent_gears = get_adjacent_cells_like(engine, c, gear_definition);
         // add them to map with gear cell as key
         for(cell adjacent_gear : adjacent_gears)
            gears_to_numbers[adjacent_gear].insert(number.value());
         c = last_num_cell;
      }
   }
   while(grid::move_to_next_cell(c, first_cell, last_cell));

   // showdown!
   ll result_sum=0;
   for(auto [gear, numbers] : gears_to_numbers)
      if(numbers.size() == 2)
         result_sum += std::ranges::fold_left(numbers, 1, std::multiplies<>());

   return result_sum;
}

}
