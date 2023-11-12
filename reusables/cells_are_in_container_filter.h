//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_CELLS_ARE_IN_CONTAINER_FILTER_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_CELLS_ARE_IN_CONTAINER_FILTER_H

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

inline std::vector<cell> cells_are_in_container_filter(
   const std::vector<cell>& cells,
   const std::unordered_set<cell>& container)
{
   std::vector<cell> filtered;
   for(auto c : cells)
      if(container.contains(c))
         filtered.push_back(c);
   return filtered;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_CELLS_ARE_IN_CONTAINER_FILTER_H
