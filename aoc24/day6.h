#pragma once

#include "everything_bagel.h"

namespace aoc24::d6 {
inline pair<cell, direction>
get_next_state (
   const grid::type<char>& map,
   pair<cell, direction> guard_state,
   string_view obstacle_chars = "#"
) {
   direction next_direction = guard_state.second;
   cell next_cell = grid::move_screen(guard_state.first, next_direction);
   while (grid::is_in(map, next_cell) && obstacle_chars.contains(grid::access(map, next_cell))) {
      next_direction = turn(next_direction, 90);
      next_cell = grid::move_screen(guard_state.first, next_direction);
   }
   return {next_cell, next_direction};
}

inline ll
p1 (vec<string> input) {
   auto map = mzlib::grid::convert_to_grid<char>(input);

   pair guard_state{
      grid::get_all_cells_with_value(map, '^')[0],
      direction::n
   };

   uset<pair<cell, direction>> visited;
   while (!visited.contains(guard_state)) {
      visited.insert(guard_state);
      grid::access(map, guard_state.first) = 'X';
      auto next_guard_state = get_next_state(map, guard_state);
      if (!grid::is_in(map, next_guard_state.first)) break;
      guard_state = next_guard_state;
   }

   auto count = grid::get_all_cells_with_value(map, 'X').size();
   return count;
}

struct floorplan_state {
   mzlib::grid::type<char> floorplan;
   pair<cell, direction> guard_state;
   cell obstacle;
};

inline bool
is_loop (
   const grid::type<char>& floorplan,
   pair<cell, direction> guard_state
) {
   uset<pair<cell, direction>> visited;
   while (true) {
      if (visited.contains(guard_state)) {
         return true; // same state twice, that's a loop
      }
      visited.insert(guard_state);
      auto next_guard_state = get_next_state(floorplan, guard_state, "#O");
      if (!grid::is_in(floorplan, next_guard_state.first)) {
         return false; // of the map
      }

      guard_state = next_guard_state;
   }
}


inline ll
p2 (vec<string> input) {
   const auto floorplan = mzlib::grid::convert_to_grid<char>(input);
   pair original_guard_state{
      grid::get_all_cells_with_value(floorplan, '^')[0],
      direction::n
   };

   vec<floorplan_state> speculations;

   uset<pair<cell, direction>> visited;
   auto guard_state = original_guard_state;
   while (!visited.contains(guard_state)) {
      visited.insert(guard_state);

      auto next_guard_state = get_next_state(floorplan, guard_state);
      if (!grid::is_in(floorplan, next_guard_state.first)) break;

      // speculation: what if where the guard is going next, was an obstacle?
      if (original_guard_state.first != next_guard_state.first) {
         auto& it = speculations.emplace_back(
            floorplan,
            original_guard_state,
            next_guard_state.first);
         grid::access(it.floorplan, next_guard_state.first) = 'O';
      }

      guard_state = next_guard_state;
   }

   uset<cell> obstacles;
   for (auto speculation : speculations) {
      if (is_loop(speculation.floorplan, speculation.guard_state)) {
         obstacles.insert(speculation.obstacle);
      }
   }

   return obstacles.size();
}
}
