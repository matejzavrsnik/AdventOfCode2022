//
// Copyright (c) 2023 Matej Zavrsnik
//
// Web:  matejzavrsnik.com
// Mail: matejzavrsnik@gmail.com
//

#pragma once

#include "grid/move_screen.h"
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

template<typename T>
std::pair<T, T>
get_interval_extremes(
   const std::vector<std::pair<T, T>>& intervals)
{
   auto min = std::min_element(
      intervals.begin(), intervals.end(),
      [](auto a, auto b){
         return a.first < b.first;
      });
   auto max = std::max_element(
      intervals.begin(), intervals.end(),
      [](auto a, auto b){
         return a.second < b.second;
      });
   return {min->first, max->second};
}


