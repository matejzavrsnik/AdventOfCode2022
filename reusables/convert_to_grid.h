//
// Created by matej on 11/11/23.
//

#ifndef RECREATIONAL_REUSABLES_SHORTEST_PATH_BFS_CPP_CONVERT_TO_GRID_H
#define RECREATIONAL_REUSABLES_SHORTEST_PATH_BFS_CPP_CONVERT_TO_GRID_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "shortest_path_bfs.h"

template<typename T>
std::vector<std::vector<T>> convert_to_grid(std::vector<std::string> vector_of_strings)
{
   std::vector<std::vector<T>> grid;
   for(auto line : vector_of_strings)
   {
      std::vector<T> row;
      for (auto cell : line)
         row.push_back(cell);
      grid.push_back(row);
   }
   return grid;
}

#endif //RECREATIONAL_REUSABLES_SHORTEST_PATH_BFS_CPP_CONVERT_TO_GRID_H
