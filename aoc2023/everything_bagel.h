// purpose: speed up development by introducing all includes, aliases, shorthands, etc in one convenient header

#pragma once

#include "grid/grid.h"

#include <unordered_set>
#include <unordered_map>

template<typename T>
using uset = std::unordered_set<T>;
using cs = std::unordered_set<mzlib::grid::cell>;
