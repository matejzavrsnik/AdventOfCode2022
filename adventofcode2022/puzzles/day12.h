#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "nature/vector.h"
#include "../../reusables/grabbag.h"
#include "../../reusables/shortest_path_bfs.h"
#include "../../reusables/access_cell.h"
#include "../../reusables/get_all_cells_with_value.h"
#include <numeric>
#include <ranges>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace adventofcode2022::day12
{

/*
 *                 METHOD DECLARATIONS
 */



bool ok_to_go(cell from, cell to, const vector<vector<int>>& field)
{
   return (field[to[0]][to[1]]-1 <= field[from[0]][from[1]]);
}

vector<cell> get_viable_dest(
   cell f,
   const vector<cell>& n,
   const vector<vector<int>>& field)
{
   vector<cell> viable;
   for(auto nn : n)
      if (ok_to_go(f, nn, field))
         viable.push_back(nn);
   return viable;
}

vector<cell> get_viable_src(
   cell f,
   const vector<cell>& n,
   const vector<vector<int>>& field)
{
   vector<cell> viable;
   for(auto nn : n)
      if (ok_to_go(nn, f, field))
         viable.push_back(nn);
   return viable;
}


/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   vector<vector<int>> field;
   for(auto line : input)
   {
      vector<int> row;
      for (auto cell: line)
         row.push_back(cell);
      field.push_back(row);
   }

   auto coor_start = get_all_cells_with_value(field, 'S')[0];
   auto coor_end = get_all_cells_with_value(field, 'E')[0];
   access_cell(field, coor_start) = 'a';
   access_cell(field, coor_end) = 'z';

   auto steps = shortest_path_bfs(field, coor_start, get_viable_src, get_viable_dest);

   return access_cell(steps, coor_end);
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   vector<vector<int>> field;
   for(auto line : input)
   {
      vector<int> row;
      for (auto cell: line)
         row.push_back(cell);
      field.push_back(row);
   }

   auto coor_start = get_all_cells_with_value(field, 'S')[0];
   auto coor_end = get_all_cells_with_value(field, 'E')[0];
   access_cell(field, coor_start) = 'a';
   access_cell(field, coor_end) = 'z';

   auto steps = shortest_path_bfs(field, coor_end, get_viable_dest, get_viable_src);

   auto all_as = get_all_cells_with_value(field, 'a');

   int min = numeric_limits<int>::max();
   for(auto an_a : all_as) {
      auto path = access_cell(steps, an_a);
      if (path < min)
         min = path;
   }

   return min;
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

