#pragma once

#include <abstract/direction.h>
#include <nature/vector.h>
#include <nature/screen_rectangle.h>
#include <laws/screen_rectangles.h>
#include <lang/concepts.h>
#include <string/split.h>

#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <numeric>
#include <ranges>
#include <deque>
#include "filesystem/read_write_file.h"
#include "iterators/copy_modify.h"
#include "grid/grid.h"
#include "iterators/circular_next.h"
#include "move_screen.h"

// to mzlib converters
template<class T>
inline std::unordered_set<T> to_unordered_set(const std::vector<T>& v)
{
   return std::unordered_set<T>(v.begin(), v.end());
}

using assignment_pairs = std::pair<std::pair<int, int>, std::pair<int, int>>;




