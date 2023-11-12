//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_TO_NEXT_PIXEL_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_TO_NEXT_PIXEL_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "grid/grid.h"
#include "iterators/copy_modify.h"
#include "filesystem/read_write_file.h"
#include "grabbag.h"
#include <deque>
#include <ranges>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <string/split.h>
#include <lang/concepts.h>
#include <laws/screen_rectangles.h>
#include <nature/screen_rectangle.h>
#include <nature/vector.h>
#include <abstract/direction.h>

// return: did it advance the coordinate? To be able to tell when to stop.
inline
bool
move_to_next_cell(
   mzlib::grid::cell& c,
   const mzlib::grid::cell& from,
   const mzlib::grid::cell& to)
{
   if(c[1] == to[1]-1 && c[0] == to[0]-1)
      return false;

   if(++c[0] >= to[0])
   {
      c[0] = from[0];
      ++c[1];
   }

   return true;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_TO_NEXT_PIXEL_H
