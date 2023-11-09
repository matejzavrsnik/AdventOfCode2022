//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_GET_INTERVAL_EXTREMES_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_GET_INTERVAL_EXTREMES_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "tools/nested_vector.h"
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

inline std::pair<int, int> get_interval_extremes(std::vector<std::pair<int, int>> intervals)
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

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_GET_INTERVAL_EXTREMES_H
