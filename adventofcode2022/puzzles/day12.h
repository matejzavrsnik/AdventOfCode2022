#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "nature/vector.h"
#include "../../reusables/shortest_path_bfs.h"
#include "../../reusables/get_all_cells_with_value.h"
#include <numeric>
#include <ranges>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include "tools/converters.h"

using namespace std;

namespace adventofcode2022::day12
{

/*
 *                 METHOD DECLARATIONS
 */


inline
bool ok_to_go(mzlib::grid::cell from, mzlib::grid::cell to, const vector<vector<int>>& field)
{
   return (
      mzlib::grid::access(field, to)-1 <=
      mzlib::grid::access(field, from));
      //field[to[0]][to[1]]-1 <= field[from[0]][from[1]]);
}

inline
vector<mzlib::grid::cell> get_viable_dest(
   const vector<vector<int>>& field,
   const vector<mzlib::grid::cell>& n,
   mzlib::grid::cell f
   )
{
   vector<mzlib::grid::cell> viable;
   for(auto nn : n)
      if (ok_to_go(f, nn, field))
         viable.push_back(nn);
   return viable;
}

inline
vector<mzlib::grid::cell> get_viable_src(
   const vector<vector<int>>& field,
   const vector<mzlib::grid::cell>& n,
   mzlib::grid::cell f
   )
{
   vector<mzlib::grid::cell> viable;
   for(auto nn : n)
      if (ok_to_go(nn, f, field))
         viable.push_back(nn);
   return viable;
}

template<class ViableNextStepInvokable>
std::vector<std::vector<int>>
single_source_shortest_path_bfs (
   std::vector<std::vector<int>>& field,
   const mzlib::grid::cell& coor_start,
   ViableNextStepInvokable allowed_transition,
   ViableNextStepInvokable get_allowed_destination_cells_fun
)
{
   std::vector<std::vector<int>> steps = field;
   set_all_cells_to_value(steps, std::numeric_limits<int>::max());

   std::unordered_set<mzlib::grid::cell> discovered_cells; // discovered
   std::unordered_set<mzlib::grid::cell> undiscovered_cells = mzlib::to_unordered_set(get_all_cells(field)); // undiscovered
   std::unordered_set<mzlib::grid::cell> frontier_cells; // frontier_cells

   frontier_cells.insert(coor_start);
   undiscovered_cells.erase(coor_start);

   bool problem_shrank = false;
   while(!undiscovered_cells.empty() || !frontier_cells.empty())
   {
      std::unordered_set<mzlib::grid::cell> next_frontier;
      problem_shrank = false;

      for(auto frontier_cell : frontier_cells) {
         //cout << "frontier_cell: " << frontier_cell << endl;
         auto neighbours = get_neighbouring_cells(field, frontier_cell);

         // from discovered_neigbours neighbours I want direction
         auto discovered_neigbours = cells_are_in_container_filter(neighbours, discovered_cells);

         auto possible_source = allowed_transition(field, discovered_neigbours, frontier_cell);

         //cout << "discovered_neigbours: ";
         //print_container_template(discovered_neigbours);
         //cout << endl;
         if(possible_source.size()>0)
         {
            auto min_neighbour = *min(possible_source.begin(), possible_source.end());
            auto min_steps = mzlib::grid::access(steps, min_neighbour); //steps[min_neighbour[0]][min_neighbour[1]];
            mzlib::grid::access(steps, frontier_cell) = min_steps + 1;
            //steps[frontier_cell[0]][frontier_cell[1]] = min_steps + 1;
         }
         else
         {
            mzlib::grid::access(steps, frontier_cell) = 0;
            //steps[frontier_cell[0]][frontier_cell[1]] = 0;
         }

         // frontier_cell is now discovered_neigbours
         discovered_cells.insert(frontier_cell);

         // undiscovered neighbours move to new frontier_cells
         auto undiscovered = cells_are_in_container_filter(neighbours, undiscovered_cells);
         //cout << "undiscovered: ";
         //print_container_template(undiscovered);
         //cout << endl;
         auto possible_destinations = get_allowed_destination_cells_fun(field, undiscovered, frontier_cell);
         //cout << "1 step: ";
         //print_container_template(possible_destinations);
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
//print_field(steps, {{2147483647, "?"}}, 3);
      frontier_cells = next_frontier;
   }
   //print_field(steps, {{2147483647, "?"}}, 3);
   return steps;
}

/*
 *                 FOR SUBMISSIONS
 */

inline long
part1_impl(std::vector<std::string> input)
{
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
   mzlib::grid::access(field, coor_start) = 'a';
   mzlib::grid::access(field, coor_end) = 'z';

   auto steps = single_source_shortest_path_bfs(field, coor_start, get_viable_src, get_viable_dest);

   return mzlib::grid::access(steps, coor_end);
}

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   long steps = part1_impl(input);

   return steps;
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
   mzlib::grid::access(field, coor_start) = 'a';
   mzlib::grid::access(field, coor_end) = 'z';

   auto steps = single_source_shortest_path_bfs(field, coor_end, get_viable_dest, get_viable_src);
//print_field(steps, {{2147483647, "?"}}, 3);
   auto all_as = get_all_cells_with_value(field, 'a');

   int min = numeric_limits<int>::max();
   for(auto an_a : all_as) {
      auto path = mzlib::grid::access(steps, an_a);
      if (path < min)
         min = path;
   }

   return mzlib::grid::access(field, coor_end);
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

