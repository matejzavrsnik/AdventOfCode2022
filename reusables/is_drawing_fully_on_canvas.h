//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_IS_DRAWING_FULLY_ON_CANVAS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_IS_DRAWING_FULLY_ON_CANVAS_H

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

inline bool is_drawing_fully_on_canvas(
   const mnvt& canvas,
   const mnvt& drawing,
   const mc2d& coor)
{
   return coor[0]>=0
      && coor[1]>=0
      && mzlib::nested_vector::width(canvas) >= coor[0] + mzlib::nested_vector::width(drawing)
      && mzlib::nested_vector::height(canvas) >= coor[1] + mzlib::nested_vector::height(drawing);
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_IS_DRAWING_FULLY_ON_CANVAS_H
