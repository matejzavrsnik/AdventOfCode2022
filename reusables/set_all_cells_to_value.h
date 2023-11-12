//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_SET_ALL_CELLS_TO_VALUE_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_SET_ALL_CELLS_TO_VALUE_H

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

inline void set_all_cells_to_value(
   mzlib::grid::type<int>& field,
   int value)
{
   for(int row = 0; row < field.size(); ++row)
      for(int col = 0; col < field[0].size(); ++col)
         field[row][col] = value;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_SET_ALL_CELLS_TO_VALUE_H
