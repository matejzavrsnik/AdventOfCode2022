// purpose: speed up development by introducing all includes, aliases, shorthands, etc
// in one convenient header.

#pragma once

// my lib includes
#include "filesystem/read_write_file.h"
#include "grid/grid.h"
#include "grid/convert_to_grid.h"
#include "grid/move_to_next_cell.h"
#include "grid/move_cartesian.h"
#include "grid/is_in.h"
#include "grid/get_neighbour_cells.h"
#include "grid/get_all_cells.h"
#include "lang/exceptions.h"
#include "printers/print_generic.h"
#include "printers/print_iterables.h"
#include "printers/print_std_pair.h"
#include "string/replace.h"
#include "iterators/starts_with.h"
#include "string/split.h"
#include "string/trim.h"

// abseil includes
#include <absl/algorithm/container.h>
#include <absl/utility/utility.h>

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

// std lib aliases
template<typename T> using uset = std::unordered_set<T>;
template<typename T> using set = std::set<T>;
template<typename T, typename U> using umap = std::unordered_map<T, U>;
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
using std::optional;
using std::nullopt;

using ll = long long;

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

// tools reusable in aoc23
// future additions to my lib, perhaps

// obnoxious!
inline string ctos(char c) { return string(1, c); }
