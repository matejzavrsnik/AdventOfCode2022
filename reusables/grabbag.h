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
#include "tools/nested_vector.h"
#include "iterators/circular_next.h"
#include "move_screen.h"


template<class Container>
void print(const Container& c){
   std::cout << "[";
   for (const auto& e: c) std::cout << e << ",";
   std::cout << "]";
}

template<class Container>
void print_field(const Container& field, std::map<int,std::string> substitutions={}, int align=2){
   for (const auto& row : field)
   {
      for (const auto& el: row)
      {
         if (substitutions.contains(el))
            std::cout << std::setfill(' ') << std::setw(align) << substitutions[el];
         else std::cout << std::setfill(' ') << std::setw(align) << el;
      }
      std::cout << std::endl;
   }
}


// to mzlib converters
template<class T>
inline std::unordered_set<T> to_unordered_set(const std::vector<T>& v)
{
   return std::unordered_set<T>(v.begin(), v.end());
}

using cell = mzlib::coordinates2d;
using assignment_pairs = std::pair<std::pair<int, int>, std::pair<int, int>>;
using cell_set = std::unordered_set<cell>;
using mnvt = mzlib::nested_vector::type<int>;
namespace mnv = mzlib::nested_vector;
using mc2d = mzlib::coordinates2d;


