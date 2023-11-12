//
// Created by matej on 08/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_CPP_GET_DIRECTION_CARTESIAN_H
#define RECREATIONAL_REUSABLES_GRABBAG_CPP_GET_DIRECTION_CARTESIAN_H

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
#include <lang/concepts.h>
#include <laws/screen_rectangles.h>
#include <nature/screen_rectangle.h>
#include <nature/vector.h>
#include <abstract/direction.h>
#include "tools/grid.h"

inline
mzlib::direction
get_direction_cartesian(
   const mzlib::grid::cell& from,
   const mzlib::grid::cell& to)
{
   auto dir_v = to-from;

   if(dir_v[0] == 0 && dir_v[1] > 0) return mzlib::direction::n;
   if(dir_v[0] == 0 && dir_v[1] < 0) return mzlib::direction::s;
   if(dir_v[0] > 0 && dir_v[1] == 0) return mzlib::direction::e;
   if(dir_v[0] < 0 && dir_v[1] == 0) return mzlib::direction::w;

   if(dir_v[0] > 0 && dir_v[1] > 0) return mzlib::direction::ne;
   if(dir_v[0] < 0 && dir_v[1] > 0) return mzlib::direction::nw;
   if(dir_v[0] > 0 && dir_v[1] < 0) return mzlib::direction::se;
   if(dir_v[0] < 0 && dir_v[1] < 0) return mzlib::direction::sw;

   return mzlib::direction::centre;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_CPP_GET_DIRECTION_CARTESIAN_H
