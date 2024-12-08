#pragma once

#include "everything_bagel.h"

namespace aoc24::d8
{

inline ll
p1 (vec<string> input)
{
   auto g = grid::convert_to_grid<char>(input);

   // get all cells with any frequency
   map<char, set<cell>> freq_loc;
   auto all_cells = grid::get_all_cells(g);
   for (auto cell : all_cells)
      if (grid::access(g, cell) != '.')
         freq_loc[grid::access(g, cell)].insert(cell);

   // for each pair, calculate # using distance * 2
   set<cell> antinodes;
   for (auto [freq, locations] : freq_loc)
      for (auto loc1 : locations)
         for (auto loc2 : locations)
            if (loc1 != loc2) {
               // A[5,2] -> B[4,4] -> [3,6] = [4-5+4, 4-2+4] = (B-A)+B
               auto antinode_loc = loc2+(loc2-loc1);
               if (grid::is_in(g, antinode_loc))
                     antinodes.insert(antinode_loc);
            }

   // set of #, size, is result
   return antinodes.size();
}

inline ll
p2 (vec<string> input)
{
   auto g = grid::convert_to_grid<char>(input);

   // get all cells with any frequency
   map<char, set<cell>> freq_loc;
   auto all_cells = grid::get_all_cells(g);
   for (auto cell : all_cells)
      if (grid::access(g, cell) != '.')
         freq_loc[grid::access(g, cell)].insert(cell);

   // for each pair, calculate # using distance * 2
   set<cell> antinodes;
   for (auto [freq, locations] : freq_loc)
      for (auto loc1 : locations)
         for (auto loc2 : locations)
            if (loc1 != loc2) {
               // A[5,2] -> B[4,4] -> [3,6] = [4-5+4, 4-2+4] = (B-A)+B
               auto increment = loc2-loc1;
               cell antinode_loc = loc2;
               while (grid::is_in(g, antinode_loc)) {
                  antinodes.insert(antinode_loc);
                  grid::access(g, antinode_loc) = '#';
                  antinode_loc += increment;
               }
            }

   // set of #, size, is result
   return antinodes.size();
}

}
