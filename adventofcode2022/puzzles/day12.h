#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "nature/vector.h"
#include "../../reusables/grabbag.h"
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

using cell_set = unordered_set<cell>;

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


template<class ViableNextStepInvokable>
vector<vector<int>>
shortest_path (
   vector<vector<int>>& field,
   const cell& coor_start,
   ViableNextStepInvokable get_viable_src,
   ViableNextStepInvokable get_viable_dest
)
{
   vector<vector<int>> steps = field;
   set_cells(steps, numeric_limits<int>::max());

   cell_set discovered_cells; // discovered
   cell_set undiscovered_cells = to_unordered_set(get_cells_coors(field)); // undiscovered
   cell_set frontier_cells; // frontier_cells

   frontier_cells.insert(coor_start);
   undiscovered_cells.erase(coor_start);

   bool problem_shrank = false;
   while(!undiscovered_cells.empty())
   {
      cell_set next_frontier;
      problem_shrank = false;
      for(auto frontier_cell : frontier_cells) {
         //cout << "frontier_cell: " << frontier_cell << endl;
         auto neighbours = get_neighbours(field, frontier_cell);

         // from discovered neighbours I want direction
         auto discovered = filter_are_in(neighbours, discovered_cells);
         auto possible_source = get_viable_src(frontier_cell, discovered, field);
         //cout << "discovered: ";
         //print(discovered);
         //cout << endl;
         if(possible_source.size()>0)
         {
            auto min_neighbour = *min(possible_source.begin(), possible_source.end());
            auto min_steps = steps[min_neighbour[0]][min_neighbour[1]];
            steps[frontier_cell[0]][frontier_cell[1]] = min_steps + 1;
         }
         else
         {
            steps[frontier_cell[0]][frontier_cell[1]] = 0;
         }

         // frontier_cell is now discovered
         discovered_cells.insert(frontier_cell);

         // undiscovered neighbours move to new frontier_cells
         auto undiscovered = filter_are_in(neighbours, undiscovered_cells);
         //cout << "undiscovered: ";
         //print(undiscovered);
         //cout << endl;
         auto possible_destinations = get_viable_dest(frontier_cell, undiscovered, field);
         //cout << "1 step: ";
         //print(possible_destinations);
         //cout << endl;
         for(auto possible_destination : possible_destinations)
         {
            next_frontier.insert(possible_destination);
            undiscovered_cells.erase(possible_destination);
            problem_shrank = true;
         }
      }
      //print_field_nodelim(steps, {{numeric_limits<int>::max(), "."}});
      //cout << endl << "=========" << endl;

      if (!problem_shrank)
         break; // none of the frontier cell_set were successful in progressing

      frontier_cells = next_frontier;
   }

   return steps;
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

   auto coor_start = get_cell_coors(field, 'S')[0];
   auto coor_end = get_cell_coors(field, 'E')[0];
   ref(field, coor_start) = 'a';
   ref(field, coor_end) = 'z';

   auto steps = shortest_path(field, coor_start, get_viable_src, get_viable_dest);

   return ref(steps, coor_end);
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

   auto coor_start = get_cell_coors(field, 'S')[0];
   auto coor_end = get_cell_coors(field, 'E')[0];
   ref(field, coor_start) = 'a';
   ref(field, coor_end) = 'z';

   auto steps = shortest_path(field, coor_end, get_viable_dest, get_viable_src);

   auto all_as = get_cell_coors(field, 'a');

   int min = numeric_limits<int>::max();
   for(auto an_a : all_as) {
      auto path = ref(steps, an_a);
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

