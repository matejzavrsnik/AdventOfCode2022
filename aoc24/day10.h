#pragma once

#include "everything_bagel.h"

namespace aoc24::d10
{

inline ll
trailhead_score (
   const grid::type<char>& g,
   const cell& trailhead
) {
   ll score =0;

   set<cell> visited;
   set<cell> frontier;

   frontier.insert(trailhead);
   while (!frontier.empty()) {
      auto current = *frontier.begin();
      auto next_steps = grid::get_neighbouring_cells(g, current);
      visited.insert(current);
      frontier.erase(current);
      for (const auto& next_step : next_steps) {
         if (visited.contains(next_step)) continue;
         if (frontier.contains(next_step)) continue;
         if (!grid::destination_exactly_one_larger(g, current, next_step)) continue;
         if (grid::access(g, next_step)=='9') ++score;
         frontier.insert(next_step);
      }
   }

   return score;
}

inline ll
p1 (vec<string> input)
{
   auto m = grid::convert_to_grid<char>(input);

   auto trailheads = grid::get_all_cells_with_value(m, '0');

   ll score=0;
   for (const auto& trailhead : trailheads)
      score+=trailhead_score(m, trailhead);

   return score;
}

inline ll
trailhead_rating (
   const grid::type<char>& g,
   const cell& trailhead
) {
   ll score = 0;

   auto next_steps = grid::get_neighbouring_cells(g, trailhead);
   for (const auto& next_step : next_steps) {
      if (!grid::destination_exactly_one_larger(g, trailhead, next_step)) continue;
      if (grid::access(g, next_step)=='9') score += 1;
      else score += trailhead_rating(g, next_step);
   }

   return score;
}

inline ll
p2 (vec<string> input)
{
   auto m = grid::convert_to_grid<char>(input);

   auto trailheads = grid::get_all_cells_with_value(m, '0');

   ll score=0;
   for (auto trailhead : trailheads)
      score+=trailhead_rating(m, trailhead);

   return score;
}

}
