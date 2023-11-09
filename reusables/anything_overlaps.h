//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H

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

inline bool anything_overlaps(const mnvt& chamber)
{
   for(const auto& row : chamber)
      for(const auto& cell : row)
         if(cell > 1)
            return true;
   return false;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_ANYTHING_OVERLAPS_H
