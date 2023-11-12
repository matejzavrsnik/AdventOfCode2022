//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_REMOVE_JUST_ONE_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_REMOVE_JUST_ONE_H

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

// removes just one elements from multiset, which isn't a feature otherwise
template <class Type>
void
remove_just_one (
   std::multiset<Type>& window,
   const Type& element
)
{
   const auto found = std::find(window.begin(), window.end(), element);
   if (found != window.end())
      window.erase(found);
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_REMOVE_JUST_ONE_H
