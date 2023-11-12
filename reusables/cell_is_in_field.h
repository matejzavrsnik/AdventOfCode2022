//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_CELL_IS_IN_FIELD_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_CELL_IS_IN_FIELD_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "tools/grid.h"
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

inline bool cell_is_in_field(
   const std::vector<std::vector<int>>& field,
   const cell& c
)
{
   if(c[0] < 0 || c[0] > field[0].size()-1) return false;
   if(c[1] < 0 || c[1] > field.size()-1) return false;
   return true;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_CELL_IS_IN_FIELD_H
