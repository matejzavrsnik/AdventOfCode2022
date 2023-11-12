//
// Created by matej on 08/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_CPP_MOVE_CARTESIAN_H
#define RECREATIONAL_REUSABLES_GRABBAG_CPP_MOVE_CARTESIAN_H


#include <nature/vector.h>
#include <abstract/direction.h>
#include "tools/grid.h"

// cartesian: like coordinate system
//
// 1
// ↑
// 0 → 1
//
// cell = {x, y}
// east = x -> increase
// north = y -> increase

inline
mzlib::grid::cell
move_cartesian(
   mzlib::grid::cell c,
   const mzlib::direction d)
{
   switch (d)
   {
   case mzlib::direction::n: c += mzlib::vector2_t<long>{0,1}; break;
   case mzlib::direction::s: c += mzlib::vector2_t<long>{0,-1}; break;
   case mzlib::direction::e: c += mzlib::vector2_t<long>{1,0}; break;
   case mzlib::direction::w: c += mzlib::vector2_t<long>{-1,0}; break;

   case mzlib::direction::ne: c += mzlib::vector2_t<long>{1,1}; break;
   case mzlib::direction::nw: c += mzlib::vector2_t<long>{-1,1}; break;
   case mzlib::direction::se: c += mzlib::vector2_t<long>{1,-1}; break;
   case mzlib::direction::sw: c += mzlib::vector2_t<long>{-1,-1}; break;
   case mzlib::direction::centre: break;
   }
   return c;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_CPP_MOVE_CARTESIAN_H
