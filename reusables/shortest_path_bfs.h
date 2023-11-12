//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H

#include "grabbag.h"
#include "cells_are_in_container_filter.h"
#include "get_neighbour_cells.h"
#include "set_all_cells_to_value.h"
#include "get_all_cells.h"

inline
std::vector<mzlib::grid::cell> all_cells_allowed(
   const mzlib::grid::type<int>& field,
   const std::vector<mzlib::grid::cell>& n,
   mzlib::grid::cell f
   )
{
   std::vector<mzlib::grid::cell> viable;
   for(auto nn : n)
      // here could be condition
      viable.push_back(nn);
   return viable;
}









inline
bool destination_at_most_one_larger(
   mzlib::grid::cell from,
   mzlib::grid::cell to,
   const mzlib::grid::type<int>& field)
{
   return
      mzlib::grid::access(field, to) - 1 <=
      mzlib::grid::access(field, from);
}

inline
std::vector<mzlib::grid::cell> allowed_transition_to(
   const mzlib::grid::type<int>& field,
   const std::vector<mzlib::grid::cell>& candidate_destinations,
   mzlib::grid::cell from,
   typeof(destination_at_most_one_larger) allowed_transition
)
{
   std::vector<mzlib::grid::cell> allowed;
   for(auto to : candidate_destinations)
      if (allowed_transition(from, to, field))
         allowed.push_back(to);
   return allowed;
}



inline
std::vector<mzlib::grid::cell>
allowed_transition_from (
   const mzlib::grid::type<int>& field,
   const std::vector<mzlib::grid::cell>& candidate_sources,
   mzlib::grid::cell to,
   typeof(destination_at_most_one_larger) allowed_transition
)
{
   std::vector<mzlib::grid::cell> allowed;
   for(auto from : candidate_sources)
      if (allowed_transition(from, to, field))
         allowed.push_back(from);
   return allowed;
}

inline
mzlib::grid::type<int>
single_source_shortest_path_bfs (
   mzlib::grid::type<int>& field,
   const mzlib::grid::cell& coor_start,
   typeof(destination_at_most_one_larger) allowed_transition = destination_at_most_one_larger
)
{
   mzlib::grid::type<int> steps = field;
   set_all_cells_to_value(steps, std::numeric_limits<int>::max());

   cell_set discovered_cells; // discovered
   cell_set undiscovered_cells = to_unordered_set(get_all_cells(field)); // undiscovered
   cell_set frontier_cells; // frontier_cells

   frontier_cells.insert(coor_start);
   undiscovered_cells.erase(coor_start);

   bool problem_shrank = false;
   while(!undiscovered_cells.empty() || !frontier_cells.empty())
   {
      cell_set next_frontier;
      problem_shrank = false;

      for(auto frontier_cell : frontier_cells) {
         //cout << "frontier_cell: " << frontier_cell << endl;
         auto neighbours = get_neighbour_cells(field, frontier_cell);

         // from discovered_neigbours neighbours I want direction
         auto discovered_neigbours = cells_are_in_container_filter(neighbours, discovered_cells);

         auto possible_source = allowed_transition_from(field, discovered_neigbours, frontier_cell, destination_at_most_one_larger);

         //cout << "discovered_neigbours: ";
         //print(discovered_neigbours);
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
         //print(undiscovered);
         //cout << endl;
         auto possible_destinations = allowed_transition_to(field, undiscovered, frontier_cell, destination_at_most_one_larger);
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
//print_field(steps, {{2147483647, "?"}}, 3);
      frontier_cells = next_frontier;
   }
   //print_field(steps, {{2147483647, "?"}}, 3);
   return steps;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H
