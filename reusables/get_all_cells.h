//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_GET_ALL_CELLS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_GET_ALL_CELLS_H

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

inline
std::vector<mzlib::grid::cell>
get_all_cells(
   const mzlib::grid::type<int>& field)
{
   std::vector<mzlib::grid::cell> all;
   for(int y = 0; y < field.size(); ++y)
      for(int x = 0; x < field[0].size(); ++x)
         all.push_back(mzlib::grid::cell{x,y});
   return all;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_GET_ALL_CELLS_H
