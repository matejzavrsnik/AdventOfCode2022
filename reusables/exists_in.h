//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H

#include "grid/grid.h"

template<typename T, typename Predicate>
bool
exists_in(
   const mzlib::grid::type<T>& g,
   Predicate pred)
{
   for(const auto& row : g)
      for(const auto& cell_value : row)
         if(pred(cell_value))
            return true;
   return false;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H
