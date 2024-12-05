#pragma once

#include "everything_bagel.h"

namespace aoc24::d4
{

inline bool
xmas(const gridt<char> g, cell c, direction d) {
   string s;
   for (auto step=0; step<4; ++step) {
      if (!grid::is_in(g, c)) return false;
      s += grid::access(g, c);
      c = grid::move_screen(c, d);
   }
   return s == "XMAS";
}

inline bool
xmas_faster(const gridt<char> g, cell c, direction d) {
   string s = "XMAS";
   for (auto step=0; step<4; ++step) {
      if (!grid::is_in(g, c)) return false;
      if (grid::access(g, c) != s[step]) return false;
      c = grid::move_screen(c, d);
   }
   return true;
}

inline ll
p1 (vec<string> input)
{
   const gridt<char> g = grid::convert_to_grid<char>(input);
   int count=0;
   for (int w = 0; w < grid::width(g); ++w)
      for (int h = 0; h < grid::width(g); ++h) {
         cell c{w, h};
         if (xmas_faster(g, c, direction::e)) ++count;
         if (xmas_faster(g, c, direction::se)) ++count;
         if (xmas_faster(g, c, direction::s)) ++count;
         if (xmas_faster(g, c, direction::sw)) ++count;
         if (xmas_faster(g, c, direction::w)) ++count;
         if (xmas_faster(g, c, direction::nw)) ++count;
         if (xmas_faster(g, c, direction::n)) ++count;
         if (xmas_faster(g, c, direction::ne)) ++count;
      }
   return count;
}

inline ll
p2 (vec<string> input)
{
   const gridt<char> g = grid::convert_to_grid<char>(input);
   int count=0;

   vec<gridt<char>> xmases = {
      {
         {'M', '.', 'S'},
         {'.', 'A', '.'},
         {'M', '.', 'S'}
      },
      {
         {'M', '.', 'M'},
         {'.', 'A', '.'},
         {'S', '.', 'S'}
      },
      {
         {'S', '.', 'M'},
         {'.', 'A', '.'},
         {'S', '.', 'M'}
      },
      {
         {'S', '.', 'S'},
         {'.', 'A', '.'},
         {'M', '.', 'M'}
      },
   };

   for (auto xmas : xmases)
      for (int w = 0; w < grid::width(g)-2; ++w)
         for (int h = 0; h < grid::width(g)-2; ++h) {
            cell c{w, h};
            if (mzlib::grid::check_for_drawing(g, xmas, c)) ++count;
         }
   return count;
}

}
