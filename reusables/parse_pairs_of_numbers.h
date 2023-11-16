//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_PARSE_PAIRS_OF_NUMBERS_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_PARSE_PAIRS_OF_NUMBERS_H

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

// parse_pairs_of_numbers the line in file into pair of pairs. format: 41-42,40-40
inline
std::pair<std::pair<int, int>, std::pair<int, int>>
parse_pairs_of_numbers (
   std::string s)
{
   auto elfs = mzlib::split(s, ",");
   auto assignment1 = mzlib::split(elfs[0], "-");
   auto assignment2 = mzlib::split(elfs[1], "-");

   return {{std::stoi(assignment1[0].data()), std::stoi(assignment1[1].data())},
      {std::stoi(assignment2[0].data()), std::stoi(assignment2[1].data())}};
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_PARSE_PAIRS_OF_NUMBERS_H
