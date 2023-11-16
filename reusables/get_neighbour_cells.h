//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_GET_NEIGHBOUR_CELLS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_GET_NEIGHBOUR_CELLS_H

#include "cell_is_in_field.h"

inline
std::vector<mzlib::grid::cell>
get_neighbouring_cells(
   const mzlib::grid::type<int>& field,
   const mzlib::grid::cell& c
)
{
   std::vector<mzlib::grid::cell> v{
      mzlib::grid::cell{c[0]+1, c[1]},
      mzlib::grid::cell{c[0]-1, c[1]},
      mzlib::grid::cell{c[0], c[1]+1},
      mzlib::grid::cell{c[0], c[1]-1}
   };
   std::vector<mzlib::coordinates2d> r;
   for(auto it = v.begin(); it!=v.end(); ++it)
      if (cell_is_in_field(field, *it))
         r.push_back(*it);
   return r;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_GET_NEIGHBOUR_CELLS_H
