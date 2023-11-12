//
// Created by matej on 08/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_ARE_TOUCHING_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_ARE_TOUCHING_H

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

// touching or not is same in cartesian and screen coordinates
inline
bool are_touching(const mzlib::grid::cell& a, const mzlib::grid::cell& b)
{
   auto diff = a - b;
   return abs(diff[0]) <= 1 && abs(diff[1]) <= 1;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_ARE_TOUCHING_H
