//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H

//#include "grabbag.h"
#include "cells_are_in_container_filter.h"
#include "get_neighbour_cells.h"
#include "set_all_cells_to_value.h"
#include "get_all_cells.h"
#include "printers/print_iterables.h"

template<typename T>
bool
all_cells_allowed (
   const mzlib::grid::type<T>& grid,
   const mzlib::grid::cell& from,
   const mzlib::grid::cell& to
)
{
   return true;
}

template<typename T>
using allowed_transition_fun_t = decltype(all_cells_allowed<T>);

template<typename T>
bool
destination_at_most_one_larger (
   const mzlib::grid::type<T>& grid,
   const mzlib::grid::cell& from,
   const mzlib::grid::cell& to
)
{
   return
      mzlib::grid::access(grid, to) - 1 <=
      mzlib::grid::access(grid, from);
}

namespace internal
{

template<typename T>
std::vector<mzlib::grid::cell>
allowed_transition_to (
   const mzlib::grid::type<T>& grid,
   const std::vector<mzlib::grid::cell>& candidate_destinations,
   const mzlib::grid::cell& from,
   allowed_transition_fun_t<T> allowed_transition
)
{
   std::vector<mzlib::grid::cell> allowed;
   for (auto to: candidate_destinations)
      if (allowed_transition(grid, from, to))
         allowed.push_back(to);
   return allowed;
}

template<typename T>
std::vector<mzlib::grid::cell>
allowed_transition_from (
   const mzlib::grid::type<T>& grid,
   const std::vector<mzlib::grid::cell>& candidate_sources,
   const mzlib::grid::cell& to,
   allowed_transition_fun_t<T> allowed_transition
)
{
   std::vector<mzlib::grid::cell> allowed;
   for (auto from: candidate_sources)
      if (allowed_transition(grid, from, to))
         allowed.push_back(from);
   return allowed;
}

}

template<typename T>
mzlib::grid::type<long>
single_source_shortest_path_bfs (
   const mzlib::grid::type<T>& grid,
   const mzlib::grid::cell& start,
   allowed_transition_fun_t<T> allowed_transition)
{
   mzlib::grid::type<long> steps = mzlib::grid::construct<long>(
      mzlib::grid::size(grid),
      std::numeric_limits<long>::max());

   std::unordered_set<mzlib::grid::cell> discovered_cells;
   auto all_cells = get_all_cells(grid);
   std::unordered_set<mzlib::grid::cell> undiscovered_cells = to_unordered_set(all_cells);
   std::unordered_set<mzlib::grid::cell> frontier_cells;

   frontier_cells.insert(start);
   undiscovered_cells.erase(start);

   bool problem_shrank = false;
   while(!undiscovered_cells.empty() || !frontier_cells.empty())
   {
      std::unordered_set<mzlib::grid::cell> next_frontier;
      problem_shrank = false;
      for(auto frontier_cell : frontier_cells)
      {
         auto all_neighbours_of_cell = get_neighbouring_cells(grid, frontier_cell);
         auto discovered_neigbours = cells_are_in_container_filter(all_neighbours_of_cell, discovered_cells);

         auto possible_sources = internal::allowed_transition_from(grid, discovered_neigbours, frontier_cell, allowed_transition);

         if(possible_sources.size()>0)
         {
            // doesn't matter which, because in this algo all transitions cost 1
            auto source_cell = *possible_sources.begin();
            auto steps_to_get_this_far = mzlib::grid::access(steps, source_cell); //steps[source_cell[0]][source_cell[1]];
            mzlib::grid::access(steps, frontier_cell) = steps_to_get_this_far + 1;

            //steps[frontier_cell[0]][frontier_cell[1]] = min_steps + 1;
         }
         else
         {
            mzlib::grid::access(steps, frontier_cell) = 0;
            //steps[frontier_cell[0]][frontier_cell[1]] = 0;
         }

         // frontier_cell is now discovered_neigbours
         discovered_cells.insert(frontier_cell);

         // undiscovered all_neighbours_of_cell move to new frontier_cells
         auto undiscovered = cells_are_in_container_filter(all_neighbours_of_cell, undiscovered_cells);
         //cout << "undiscovered: ";
         //print_container_template(undiscovered);
         //cout << endl;
         auto possible_destinations = internal::allowed_transition_to(grid, undiscovered, frontier_cell, allowed_transition);
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

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H
