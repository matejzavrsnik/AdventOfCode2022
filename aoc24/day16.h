#pragma once

#include "everything_bagel.h"

namespace aoc24::d16
{

struct problem {
   cell deer_pos;
   direction deer_facing;
   ll cost;
   vec<cell> past_positions; // for debugging
};

inline ll
p1 (vec<string> input)
{
   auto g = grid::convert_to_grid<char>(input);

   auto deer_pos = grid::get_all_cells_with_value(g, 'S')[0];
   auto end_pos = grid::get_all_cells_with_value(g, 'E')[0];

   map<tuple<cell, direction>, ll/*cost*/> cell_cost;
   cell_cost[{end_pos, direction::e}] = max_ll;
   cell_cost[{end_pos, direction::s}] = max_ll;
   //cell_cost[{end_pos, direction::w}] = max_ll;
   //cell_cost[{end_pos, direction::n}] = max_ll;
   set<tuple<cell, direction>> explored;

   qu<problem> problems;
   problems.push({
      .deer_pos = deer_pos,
      .deer_facing = direction::e,
      .cost = 0
   });

   set<ll> costs;

   while (!problems.empty()) {

      const auto p = problems.front();
      problems.pop();

      if (p.deer_pos == end_pos) {
         costs.insert(p.cost);
         continue;
      }

      // four options
      // 1
      cell forward = grid::move_screen(p.deer_pos, p.deer_facing);
      const bool iswall = grid::access(g, forward) == '#';
      const bool ischeaper = !cell_cost.contains({forward, p.deer_facing}) || p.cost+1 < cell_cost[{forward, p.deer_facing}];
      if (!iswall && ischeaper) {
         problems.push({
            .deer_pos = forward,
            .deer_facing = p.deer_facing,
            .cost = p.cost + 1,
            .past_positions = p.past_positions
         });
         problems.back().past_positions.push_back(p.deer_pos);
         cell_cost[{forward, p.deer_facing}] = p.cost + 1;
      }

         int i=0;
      // 2 & 3
      for (auto turns : {90, -90}) {
         auto facing = turn(p.deer_facing, turns);
         auto f=grid::move_screen(p.deer_pos, facing);
         if (grid::access(g, f) != '#') {
            auto cell_facing = make_tuple(p.deer_pos, facing);
            if (!explored.contains(cell_facing)) {
               problems.push({
                  .deer_pos = p.deer_pos,
                  .deer_facing = facing,
                  .cost = p.cost+1000,
                  .past_positions = p.past_positions
               });
               explored.insert(cell_facing);
            }
         }
      }
   }

   auto cost = min(cell_cost[{end_pos, direction::n}], cell_cost[{end_pos, direction::s}]);
   return cost;
}

inline ll
p2 (vec<string> input)
{
   return 0;
}

}
