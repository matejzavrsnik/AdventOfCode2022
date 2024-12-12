#pragma once

#include "everything_bagel.h"

namespace aoc24::d12
{
inline ll
calc_perimeter (
   gridt<char> garden,
   set<cell> region)
{
   ll perimeter = 0;
   for (auto plot : region) {
      auto additional = 4;
      for (auto neighbour : grid::get_neighbouring_cells(garden, plot))
         if (grid::access(garden, neighbour) == grid::access(garden, plot))
            --additional;
      perimeter += additional;
   }
   return perimeter;
}

inline ll
p1 (vec<string> input)
{
   auto garden = grid::convert_to_grid<char>(input);

   set<set<cell>> regions = grid::get_all_regions(garden);

   ll fence_price =0;
   for (auto region : regions) {
      auto perimeter = calc_perimeter(garden, region);
      fence_price += region.size() * perimeter;
   }

   return fence_price;
}

inline ll
calc_sides (
   const set<cell>& region)
{
   umap<cell, uset<direction>> edge_directions;

   for (auto plot : region)
      for (auto towards : {direction::n, direction::e, direction::s, direction::w}) {
         auto cell_in_this_direction = grid::move_screen(plot, towards);
         if (!region.contains(cell_in_this_direction))
            edge_directions[plot].insert(towards);
      }

   int sides = 0;

   auto [box_top_left, box_bottom_right] = grid::get_region_box_screen(region);

   for (int j = box_top_left[1]; j <= box_bottom_right[1]; ++j) {
      for (auto towards : {direction::n, direction::s}) {
         bool contiguous = false;
         for (int i = box_top_left[0]; i <= box_bottom_right[0]; ++i) {
            cell plot{i, j};
            if (region.contains(plot) && edge_directions[plot].contains(towards)) {
               if (contiguous==false)
                  ++sides;
               contiguous=true;
            }
            else
               contiguous=false;
         }
      }
   }

   for (int i = box_top_left[0]; i <= box_bottom_right[0]; ++i) {
      for (auto towards : {direction::e, direction::w}) {
         bool contiguous = false;
         for (int j = box_top_left[1]; j <= box_bottom_right[1]; ++j) {
            cell plot{i, j};
            if (region.contains(plot) && edge_directions[plot].contains(towards)) {
               if (contiguous==false)
                  ++sides;
               contiguous=true;
            }
            else
               contiguous=false;
         }
      }
   }

   return sides;
}

inline ll
p2 (vec<string> input)
{
   auto garden = grid::convert_to_grid<char>(input);

   set<set<cell>> regions = grid::get_all_regions(garden);

   ll fence_price =0;
   for (const auto& region : regions) {
      auto sides = calc_sides(region);
      fence_price += region.size() * sides;
   }

   return fence_price;
}

}
