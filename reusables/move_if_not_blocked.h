//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_IF_NOT_BLOCKED_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_IF_NOT_BLOCKED_H

#include "grabbag.h"
#include "anything_overlaps.h"
#include "move_drawing.h"
#include "is_drawing_fully_on_canvas.h"

// return: new coordinates of the stone
inline mc2d move_if_not_blocked(
   mzlib::grid::type<int>& chamber,
   const mzlib::grid::type<int>& rock,
   const mc2d& from_coor,
   const mc2d& to_coor
)
{
   if (is_drawing_fully_on_canvas(chamber, rock, to_coor))
   {
      move_drawing(chamber, rock, from_coor, to_coor);
      // jet push can make it overlap with another stone
      if (anything_overlaps(chamber))
         // in that case move back
         move_drawing(chamber, rock, to_coor, from_coor);
      else
         // if not, this is new coordinates
         return to_coor;
   }
   // couldn't move
   return from_coor;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_IF_NOT_BLOCKED_H
