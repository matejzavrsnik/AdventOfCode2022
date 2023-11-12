//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_TRANSLATE_TO_DIRECTION_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_TRANSLATE_TO_DIRECTION_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "tools/grid.h"
#include "iterators/copy_modify.h"
#include "filesystem/read_write_file.h"
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

inline
mzlib::direction
translate_to_direction(char dir)
{
   switch(dir)
   {
   case 'L': return mzlib::direction::w; break;
   case 'R': return mzlib::direction::e; break;
   case 'U': return mzlib::direction::n; break;
   case 'D': return mzlib::direction::s; break;
   }
   std::terminate();
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_TRANSLATE_TO_DIRECTION_H
