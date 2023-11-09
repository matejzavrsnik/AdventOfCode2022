//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_GET_NEIGHBOUR_CELLS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_GET_NEIGHBOUR_CELLS_H

#include "grabbag.h"
#include "cell_is_in_field.h"

inline std::vector<mzlib::coordinates2d> get_neighbour_cells(
   const std::vector<std::vector<int>>& field,
   const cell& c
)
{
   std::vector<cell> v{
      cell{c[0]+1, c[1]},
      cell{c[0]-1, c[1]},
      cell{c[0], c[1]+1},
      cell{c[0], c[1]-1}
   };
   std::vector<mzlib::coordinates2d> r;
   for(auto it = v.begin(); it!=v.end(); ++it)
      if (cell_is_in_field(field, *it))
         r.push_back(*it);
   return r;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_GET_NEIGHBOUR_CELLS_H
