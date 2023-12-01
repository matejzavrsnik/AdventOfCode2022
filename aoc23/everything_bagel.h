// purpose: speed up development by introducing all includes, aliases, shorthands, etc
// in one convenient header.

#pragma once

#include "filesystem/read_write_file.h"
#include "grid/grid.h"
#include "lang/exceptions.h"
#include "printers/print_generic.h"
#include "printers/print_iterables.h"
#include "printers/print_std_pair.h"
#include "string/replace.h"

// std lib includes
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

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

using ll = long long;

// mzlib aliases
using usc = std::unordered_set<mzlib::grid::cell>;
using mzlib::read_file_lines;
using mzlib::print;
using mzlib::string_replace;
