//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_IF_NOT_BLOCKED_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_IF_NOT_BLOCKED_H

#include "grabbag.h"
#include "grid/exists_in.h"
#include "lang/greater_than.h"
#include "move_drawing.h"
#include "fits_on_grid.h"

template<typename T, typename Predicate = decltype(mzlib::greater_than(1))>
mzlib::grid::cell
move_unless(
   mzlib::grid::type<T>& grid,
   const mzlib::grid::type<T>& drawing,
   const mzlib::grid::cell& from,
   const mzlib::grid::cell& to,
   Predicate pred = mzlib::greater_than(1)
)
{
   if (fits_on_grid(grid, drawing, to))
   {
      // try to move first
      move_drawing(grid, drawing, from, to);
      // then check if it overlaps
      if (mzlib::grid::exists_in(grid, pred))
         // if it does, move back
         move_drawing(grid, drawing, to, from);
      else
         // if it doesn't, this is new coordinates
         return to;
   }
   // couldn't move
   return from;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_IF_NOT_BLOCKED_H
