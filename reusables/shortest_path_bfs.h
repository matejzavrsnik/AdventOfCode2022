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
std::vector<cell> get_allowed_destination_cells(
   cell f,
   const std::vector<cell>& n,
   const std::vector<std::vector<int>>& field)
{
   std::vector<cell> viable;
   for(auto nn : n)
      // here could be condition
      viable.push_back(nn);
   return viable;
}

inline
std::vector<cell> get_allowed_source_cells(
   cell f,
   const std::vector<cell>& n,
   const std::vector<std::vector<int>>& field)
{
   std::vector<cell> viable;
   for(auto nn : n)
      // here could be condition
      viable.push_back(nn);
   return viable;
}

template<class ViableNextStepInvokable>
std::vector<std::vector<int>>
shortest_path_bfs (
   std::vector<std::vector<int>>& field,
   const cell& coor_start,
   ViableNextStepInvokable get_allowed_source_cells_fun = get_allowed_source_cells,
   ViableNextStepInvokable get_allowed_destination_cells_fun = get_allowed_destination_cells
)
{
   std::vector<std::vector<int>> steps = field;
   set_all_cells_to_value(steps, std::numeric_limits<int>::max());

   cell_set discovered_cells; // discovered
   cell_set undiscovered_cells = to_unordered_set(get_all_cells(field)); // undiscovered
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
         auto neighbours = get_neighbour_cells(field, frontier_cell);

         // from discovered_neigbours neighbours I want direction
         auto discovered_neigbours = cells_are_in_container_filter(neighbours, discovered_cells);
         auto possible_source = get_allowed_source_cells_fun(frontier_cell, discovered_neigbours, field);
         //cout << "discovered_neigbours: ";
         //print(discovered_neigbours);
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

         // frontier_cell is now discovered_neigbours
         discovered_cells.insert(frontier_cell);

         // undiscovered neighbours move to new frontier_cells
         auto undiscovered = cells_are_in_container_filter(neighbours, undiscovered_cells);
         //cout << "undiscovered: ";
         //print(undiscovered);
         //cout << endl;
         auto possible_destinations = get_allowed_destination_cells_fun(frontier_cell, undiscovered, field);
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

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_SHORTEST_PATH_H
