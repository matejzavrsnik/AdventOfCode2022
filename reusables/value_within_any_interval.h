//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_VALUE_WITHIN_ANY_INTERVAL_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_VALUE_WITHIN_ANY_INTERVAL_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "grid/grid.h"
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

template<class T>
bool
value_within_any_interval(
   const std::vector<std::pair<T, T>>& intervals,
   const T& value)
{
   for (const auto& c: intervals)
      if (value >= c.first && value <= c.second)
         return true;
   return false;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_VALUE_WITHIN_ANY_INTERVAL_H
