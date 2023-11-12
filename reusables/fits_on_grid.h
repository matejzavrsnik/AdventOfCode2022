//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_IS_DRAWING_FULLY_ON_CANVAS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_IS_DRAWING_FULLY_ON_CANVAS_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "grid/grid.h"
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

template<typename T>
bool
fits_on_grid(
   const mzlib::grid::type<T>& grid,
   const mzlib::grid::type<T>& drawing,
   const mzlib::grid::cell& c)
{
   return c[0]>=0 && c[1]>=0
      && mzlib::grid::width(grid) >= c[0] + mzlib::grid::width(drawing)
      && mzlib::grid::height(grid) >= c[1] + mzlib::grid::height(drawing);
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_IS_DRAWING_FULLY_ON_CANVAS_H
