// purpose: speed up development by introducing all includes, aliases, shorthands, etc
// in one convenient header.

#pragma once

#include "grid/grid.h"

// std lib includes
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

// std lib aliases
template<typename T> using uset = std::unordered_set<T>;
template<typename T> using set = std::set<T>;
template<typename T, typename U> using umap = std::unordered_map<T, U>;
template<typename T, typename U> using map = std::map<T, U>;
template<typename T> using vec = std::vector<T>;
template<typename T, typename U> using pair = std::pair<T, U>;

// mzlib aliases
using usc = std::unordered_set<mzlib::grid::cell>;

