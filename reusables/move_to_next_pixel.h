//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_TO_NEXT_PIXEL_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_TO_NEXT_PIXEL_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "tools/nested_vector.h"
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
inline bool move_to_next_pixel(mc2d& coordinate, const mc2d& from, const mc2d& to)
{
   if(coordinate[1] == to[1]-1 && coordinate[0] == to[0]-1)
      return false;

   if(++coordinate[0] >= to[0])
   {
      coordinate[0] = from[0];
      ++coordinate[1];
   }

   return true;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_MOVE_TO_NEXT_PIXEL_H
