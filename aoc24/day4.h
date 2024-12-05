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

inline ll
p1 (vec<string> input)
{
   const gridt<char> g = grid::convert_to_grid<char>(input);
   int count=0;
   for (int w = 0; w < grid::width(g); ++w)
      for (int h = 0; h < grid::width(g); ++h) {
         cell c{w, h};
         if (xmas(g, c, direction::e)) ++count;
         if (xmas(g, c, direction::se)) ++count;
         if (xmas(g, c, direction::s)) ++count;
         if (xmas(g, c, direction::sw)) ++count;
         if (xmas(g, c, direction::w)) ++count;
         if (xmas(g, c, direction::nw)) ++count;
         if (xmas(g, c, direction::n)) ++count;
         if (xmas(g, c, direction::ne)) ++count;
      }
   return count;
}

template <typename T>
bool
check_for_drawing (
   const mzlib::grid::type<T>& grid,
   const mzlib::grid::type<T>& drawing,
   const mzlib::grid::cell& c,
   T neutral_value = '.'
)
{
   mzlib::grid::cell drawing_pixel{0, 0};
   const mzlib::grid::cell drawing_size = mzlib::grid::size(drawing);
   do
   {
      auto canvas_pixel = drawing_pixel + c;
      const auto pixel_value = mzlib::grid::access(drawing, drawing_pixel);
      if (pixel_value == neutral_value)
         continue;
      const auto value_on_grid = mzlib::grid::access(grid, canvas_pixel);
      if (value_on_grid != pixel_value)
         return false;
   }
   while (mzlib::grid::move_to_next_cell(drawing_pixel, {0, 0}, drawing_size));

   return true;
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
            if (check_for_drawing(g, xmas, c)) ++count;
         }
   return count;
}

}
