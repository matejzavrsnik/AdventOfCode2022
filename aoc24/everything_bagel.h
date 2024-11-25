// purpose: speed up development by introducing all includes, aliases, shorthands, etc
// in one convenient header.

#pragma once

// my lib includes
#include "filesystem/read_write_file.h"
#include "grid/grid.h"
#include "grid/convert_to_grid.h"
#include "grid/move_to_next_cell.h"
#include "grid/move_cartesian.h"
#include "grid/move_screen.h"
#include "grid/is_in.h"
#include "grid/get_neighbour_cells.h"
#include "grid/get_all_cells.h"
#include "grid/get_all_cells_with_value.h"
#include "lang/exceptions.h"
#include "lang/equal_to.h"
#include "lang/less_than.h"
#include "lang/greater_than.h"
#include "printers/print_generic.h"
#include "printers/print_iterables.h"
#include "printers/print_std_pair.h"
#include "string/replace.h"
#include "iterators/starts_with.h"
#include "string/split.h"
#include "string/trim.h"
#include "laws/set_difference.h"
#include "laws/set_intersection.h"
#include "tools/sets_intersection.h"
#include "tools/add_to_tally.h"
#include "tools/sort_map_by_value.h"
#include "iterators/find_subsequence.h"
#include "iterators/repeated_ranges.h"
#include "iterators/circular_next.h"

// abseil includes
#include <absl/algorithm/container.h>
#include <absl/utility/utility.h>
#include <absl/strings/str_split.h>
#include <absl/strings/str_replace.h>

// range-v3
#include <range/v3/all.hpp>

// stdlib includes
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <ranges>
#include <limits>

// std lib aliases
template<typename T> using uset = std::unordered_set<T>;
template<typename T> using mset = std::multiset<T>;
template<typename T> using set = std::set<T>;
template<typename T, typename U> using umap = std::unordered_map<T, U>;
template<typename T, typename U> using mmap = std::multimap<T, U>;
template<typename T, typename U> using map = std::map<T, U>;
template<typename T> using vec = std::vector<T>;
template<typename T, typename U> using pair = std::pair<T, U>;
template<typename T> using qu = std::queue<T>;
template<typename T> using pqu = std::priority_queue<T>;
using std::string;
using std::cout;
using std::endl;
using std::stoll;
using std::find_if;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::distance;
using std::accumulate;
template<typename T> using opt = std::optional<T>;
using std::nullopt;

using ll = long long;
static ll max_ll = std::numeric_limits<long long>::max();
static ll min_ll = std::numeric_limits<long long>::min();

// mzlib aliases
using usc = std::unordered_set<mzlib::grid::cell>;
template<typename T> using gridt = mzlib::grid::type<T>;
using mzlib::grid::cell;
namespace grid = mzlib::grid;
using mzlib::direction;
using mzlib::read_file_lines;
using mzlib::print;
using mzlib::string_replace;
using mzlib::starts_with_c;
using mzlib::split;
using mzlib::trim;
using mzlib::sets_intersection;
using mzlib::less_than;
using mzlib::greater_than;
using mzlib::equal_to;
using mzlib::add_to_tally;
using mzlib::sort_map_by_value;
using mzlib::find_subsequence;
using mzlib::repeated_sequences;
using mzlib::circular_next_iterator;

// tools reusable in aoc23
// future additions to my lib, perhaps

// common converters and predicated for range transformations, filtering, etc

inline ll strv_to_ll(std::string_view s) { return stoll(s.data()); }

inline ll str_to_ll(std::string s) { return stoll(s); }

template<typename Collection>
typename Collection::value_type
mul_all(const Collection& c) {
   return ranges::fold_left(c, 1, std::multiplies<>());
}

// collection size equals
template<long long Size, typename Collection>
bool
size_eq(const Collection& c) {
   return c.size() == Size;
}

// obnoxious!
inline string ctos(char c) { return string(1, c); }


