//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_INTERVAL_OVERLAPS_THE_OTHER_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_INTERVAL_OVERLAPS_THE_OTHER_H

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

inline
bool
interval_overlaps_the_other (
   std::pair<int, int> one,
   std::pair<int, int> other
)
{
   return one.second >= other.first && one.first <= other.second;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_INTERVAL_OVERLAPS_THE_OTHER_H
