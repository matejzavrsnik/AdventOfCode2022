//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H

#include "tools/grid.h"

inline
bool
anything_overlaps(
   const mzlib::grid::type<int>& chamber)
{
   for(const auto& row : chamber)
      for(const auto& cell : row)
         if(cell > 1)
            return true;
   return false;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H
