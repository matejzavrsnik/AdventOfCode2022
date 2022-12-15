#pragma once

#include <abstract/direction.h>
#include <nature/vector.h>
#include <nature/screen_rectangle.h>
#include <laws/screen_rectangles.h>
#include <lang/concepts.h>

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


template<class VectorT>
VectorT move_cartesian(VectorT c, const mzlib::direction d)
{
   switch (d)
   {
   case mzlib::direction::n: c += VectorT{0,1}; break;
   case mzlib::direction::s: c += VectorT{0,-1}; break;
   case mzlib::direction::e: c += VectorT{1,0}; break;
   case mzlib::direction::w: c += VectorT{-1,0}; break;

   case mzlib::direction::ne: c += VectorT{1,1}; break;
   case mzlib::direction::nw: c += VectorT{-1,1}; break;
   case mzlib::direction::se: c += VectorT{1,-1}; break;
   case mzlib::direction::sw: c += VectorT{-1,-1}; break;
   case mzlib::direction::centre: break;
   }
   return c;
}

template<class VectorT>
VectorT move_screen(VectorT c, const mzlib::direction d)
{
   switch (d)
   {
   case mzlib::direction::n: c += VectorT{0,-1}; break;
   case mzlib::direction::s: c += VectorT{0,1}; break;
   case mzlib::direction::e: c += VectorT{1,0}; break;
   case mzlib::direction::w: c += VectorT{-1,0}; break;

   case mzlib::direction::ne: c += VectorT{1,-1}; break;
   case mzlib::direction::nw: c += VectorT{-1,-1}; break;
   case mzlib::direction::se: c += VectorT{1,1}; break;
   case mzlib::direction::sw: c += VectorT{-1,1}; break;
   case mzlib::direction::centre: break;
   }
   return c;
}

template<class VectorT>
inline mzlib::direction get_direction_cartesian(VectorT from, VectorT to)
{
   auto dir_v = to-from;

   if(dir_v[0] == 0 && dir_v[1] > 0) return mzlib::direction::n;
   if(dir_v[0] == 0 && dir_v[1] < 0) return mzlib::direction::s;
   if(dir_v[0] > 0 && dir_v[1] == 0) return mzlib::direction::e;
   if(dir_v[0] < 0 && dir_v[1] == 0) return mzlib::direction::w;

   if(dir_v[0] > 0 && dir_v[1] > 0) return mzlib::direction::ne;
   if(dir_v[0] < 0 && dir_v[1] > 0) return mzlib::direction::nw;
   if(dir_v[0] > 0 && dir_v[1] < 0) return mzlib::direction::se;
   if(dir_v[0] < 0 && dir_v[1] < 0) return mzlib::direction::sw;

   return mzlib::direction::centre;
}

inline bool are_touching(mzlib::coordinates2d a, mzlib::coordinates2d b)
{
   auto diff = a - b;
   return abs(diff[0]) <= 1 && abs(diff[1]) <= 1;
}

template<class Container>
void print(const Container& c){
   std::cout << "[";
   for (const auto& e: c) std::cout << e << ",";
   std::cout << "]";
}

template<class Container>
void print_field_nodelim(const Container& field, std::map<int,std::string> subst){
   std::cout << std::setfill('.') << std::setw(2);
   for (const auto& row : field)
   {
      for (const auto& el: row)
      {
         if (subst.contains(el))
            std::cout << std::setfill(' ') << std::setw(4) << subst[el];
         else std::cout << std::setfill(' ') << std::setw(4) << el;
      }
      std::cout << std::endl;
   }
}

using cell = mzlib::coordinates2d;

inline std::vector<cell> get_cell_coors(const std::vector<std::vector<int>>& field, int value)
{
   std::vector<cell> all_of_value;
   for(int row = 0; row < field.size(); ++row)
      for(int col = 0; col < field[0].size(); ++col)
         if(field[row][col] == value)
            all_of_value.push_back(cell{row,col});
   //cout << all_of_value.size() << endl;
   return all_of_value;
}

inline std::vector<cell> get_cells_coors(const std::vector<std::vector<int>>& field)
{
   std::vector<cell> all;
   for(int row = 0; row < field.size(); ++row)
      for(int col = 0; col < field[0].size(); ++col)
         all.push_back(cell{row,col});
   return all;
}

template<class T>
inline std::unordered_set<T> to_unordered_set(const std::vector<T>& v)
{
   return std::unordered_set<T>(v.begin(), v.end());
}

inline void set_cells(
   std::vector<std::vector<int>>& field,
   int value)
{
   for(int row = 0; row < field.size(); ++row)
      for(int col = 0; col < field[0].size(); ++col)
         field[row][col] = value;
}

inline int& ref(
   std::vector<std::vector<int>>& field,
   const cell& c)
{
   return field[c[0]][c[1]];
}

inline bool is_in(
   const std::vector<std::vector<int>>& field,
   const cell& c
)
{
   if(c[0] < 0 || c[0] > field.size()-1) return false;
   if(c[1] < 0 || c[1] > field[0].size()-1) return false;
   return true;
}

inline std::vector<mzlib::coordinates2d> get_neighbours(
   const std::vector<std::vector<int>>& field,
   const cell& c
)
{
   std::vector<cell> v{
      cell{c[0]+1, c[1]},
      cell{c[0]-1, c[1]},
      cell{c[0], c[1]+1},
      cell{c[0], c[1]-1}
   };
   std::vector<mzlib::coordinates2d> r;
   for(auto it = v.begin(); it!=v.end(); ++it)
      if (is_in(field, *it))
         r.push_back(*it);
   return r;
}

inline std::vector<cell> filter_are_in(
   const std::vector<cell>& cells,
   const std::unordered_set<cell>& container)
{
   std::vector<cell> filtered;
   for(auto c : cells)
      if(container.contains(c))
         filtered.push_back(c);
   return filtered;
}

inline
long manhattan_distance(const mzlib::coordinates2d& a, const mzlib::coordinates2d& b)
{
   return abs(a[0]-b[0])+abs(a[1]-b[1]);
}

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

template<class T>
bool inside_any(
   const std::vector<std::pair<T, T>>& intervals,
   const T& value)
{
   for (const auto& c: intervals)
      if (value >= c.first && value <= c.second)
         return true;
   return false;
}
