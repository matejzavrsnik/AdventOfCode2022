#pragma once

#include "everything_bagel.h"

namespace aoc24::d14
{

ll move_coordinate(ll p, ll v, ll g, ll s) {
   if (v>0)
      return (p+s*v)%g;
   if (v<0) {
      auto p1 = (p+s*v)%g;
      return p1 >= 0 ? p1 : g+p1;
   }
   return p;
}

vec<cell>
move(
   const vec<tuple<cell, cell>>& robots,
   ll wide,
   ll tall,
   ll seconds)
{
   vec<cell> result;
   for (auto [p, v] : robots) {
      cell c {
         move_coordinate(p[0], v[0], wide, seconds),
         move_coordinate(p[1], v[1], tall, seconds)
      };
      result.push_back(c);
   }
   return result;
}

inline ll
p1 (vec<string> input, ll wide, ll tall)
{
   vec<tuple<cell, cell>> robots = input
      | sv::transform([](auto it) {
         vec<string> parts = absl::StrSplit(it, absl::ByAnyChar(" ,="), absl::SkipEmpty());
         return tuple{
         cell{stoll(parts[1]), stoll(parts[2])},
         cell{stoll(parts[4]), stoll(parts[5])}};
      })
      | sr::to<vec<tuple<cell,cell>>>();

   auto after = move(robots, wide, tall, 100);
   /*
   auto space = grid::construct(tall, wide, '.');
   for (auto r : after) {
      print(r);
      grid::access(space, r) = 'x';
   }
   print(space);
   */

   // 1 | 2
   // --+--
   // 3 | 4
   auto mid_tall = tall/2;
   auto mid_wide = wide/2;
   map<int /*quad*/, ll /*robots*/> count;
   for (auto r : after) {
      if (r[0] > mid_wide) // 2 or 4
         if (r[1] > mid_tall)
            count[4]+=1;
         else if (r[1]< mid_tall)
            count[2]+=1;
      if (r[0] < mid_wide) // 1 or 3
         if (r[1] > mid_tall)
            count[3]+=1;
         else if (r[1]< mid_tall)
            count[1]+=1;
   }

   return count[1]*count[2]*count[3]*count[4];
}

template<typename T>
grid::type<T>
flip_left_right(grid::type<T> g) {
   ll height = grid::height(g);
   ll width = grid::width(g);
   for (ll h=0; h<height; ++h) {
      for (ll w=0; w<width/2; ++w) {
         auto left = grid::access(g, w, h);
         auto right = grid::access(g, width-w-1, h);
         grid::access(g, w, h) = right;
         grid::access(g, width-w-1, h) = left;
      }
   }
   return g;
}

template<typename T>
set<cell>
different_cells(const grid::type<T>& g1, const grid::type<T>& g2) {
   set<cell> different;

   ll height = grid::height(g1);
   ll width = grid::width(g1);

   if (grid::height(g2) != height || grid::width(g2) != width)
      throw mzlib::exception::invalid_values("grids should be same size");

   for (ll h=0; h<height; ++h)
      for (ll w=0; w<width; ++w)
         if (grid::access(g1, w, h) != grid::access(g2, w, h))
            different.insert({w,h});

   return different;
}

inline ll
p2 (vec<string> input, ll wide, ll tall)
{
   vec<tuple<cell, cell>> robots = input
      | sv::transform([](auto it) {
         vec<string> parts = absl::StrSplit(it, absl::ByAnyChar(" ,="), absl::SkipEmpty());
         return tuple{
         cell{stoll(parts[1]), stoll(parts[2])},
         cell{stoll(parts[4]), stoll(parts[5])}};
      })
      | sr::to<vec<tuple<cell,cell>>>();

   ll max_symetry = max_ll;
   ll seconds_passed=0;
   map<ll, ll> symetries;
   for (int i=1; i<10000; ++i) {
      auto after = move(robots, wide, tall, i);
      auto picture = grid::construct(tall, wide, ' ');
      for (const auto& r : after) {
         grid::access(picture, r) = 'X';
      }

      auto flipped_picture = flip_left_right(picture);
      auto diff = different_cells(picture, flipped_picture);

      if (diff.size() < max_symetry) {
         max_symetry = diff.size();
         seconds_passed = i;
         // print(picture);
         // cout << i << " " << max_symetry << endl;
      }
   }

   return seconds_passed;
}

}
