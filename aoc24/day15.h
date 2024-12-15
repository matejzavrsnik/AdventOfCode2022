#pragma once

#include "everything_bagel.h"

namespace aoc24::d15
{

bool
ok_to_move (
   const grid::type<char>& g,
   cell npc,
   direction dir
) {
   auto moved_npc = grid::move_screen(npc, dir);
   if (grid::access(g, moved_npc) == '#') return false;
   if (grid::access(g, moved_npc) == 'O') return ok_to_move(g, moved_npc, dir);
   return true;
}

cell
move_npc (
   grid::type<char>& g,
   cell npc,
   direction dir
) {
   if (ok_to_move(g, npc, dir)) {
      auto moved_npc = grid::move_screen(npc, dir);
      if (grid::access(g, moved_npc) == 'O') move_npc(g, moved_npc, dir);
      grid::access(g, moved_npc) = grid::access(g, npc);
      grid::access(g, npc) = '.';
      return moved_npc;
   }
   return npc;
}

inline ll
p1 (vec<string> input)
{
   vec<string> input_warehouse;
   string input_moves;
   bool beforeemptyline = true;
   for (auto line : input) {
      if (beforeemptyline) beforeemptyline = !line.empty();
      if (beforeemptyline) input_warehouse.push_back(line);
      else input_moves.append(line);
   }

   auto g = grid::convert_to_grid<char>(input_warehouse);

   auto robot = grid::get_all_cells_with_value(g, '@')[0];

   for (auto move : input_moves) {
      auto dir = mzlib::convert<direction>(move);
      robot = move_npc(g, robot, dir);
   }

   return sr::fold_left(
      grid::get_all_cells_with_value(g, 'O') | sv::transform([](auto it){ return it[0]+it[1]*100; }),
      0, std::plus()
      );
}

bool
ok_to_move_dbl (
   const grid::type<char>& g,
   cell npc,
   direction dir
) {
   auto moved_npc = grid::move_screen(npc, dir);
   if (grid::access(g, moved_npc) == '#') return false;
   if (grid::access(g, moved_npc) == ']' || grid::access(g, moved_npc) == '[') {
      if (dir == direction::e || dir == direction::w) {
         return ok_to_move_dbl(g, moved_npc, dir);
      }
      if (dir == direction::n || dir == direction::s) {
         cell moved_npc_part2 = grid::access(g, moved_npc) == ']'
            ? grid::move_screen(moved_npc, direction::w)
            : grid::move_screen(moved_npc, direction::e);
         return ok_to_move_dbl(g, moved_npc, dir) && ok_to_move_dbl(g, moved_npc_part2, dir);
      }
   }
   return true;
}

cell
move_dbl_npc (
   grid::type<char>& g,
   cell npc,
   direction dir
) {
   if (ok_to_move_dbl(g, npc, dir)) {
      //print(npc) << "ok to move to " << dir << endl;
      auto moved_npc = grid::move_screen(npc, dir);
      //print(moved_npc);
      if (grid::access(g, moved_npc) == ']' || grid::access(g, moved_npc) == '[') {
         if (dir == direction::e || dir == direction::w) {
            move_dbl_npc(g, moved_npc, dir);
         }
         if (dir == direction::n || dir == direction::s) {
            cell moved_npc_part2;
            if (grid::access(g, moved_npc) == ']')
               moved_npc_part2 = grid::move_screen(moved_npc, direction::w);
            else
               moved_npc_part2 = grid::move_screen(moved_npc, direction::e);
            move_dbl_npc(g, moved_npc, dir);
            move_dbl_npc(g, moved_npc_part2, dir);
         }
      }
      grid::access(g, moved_npc) = grid::access(g, npc);
      grid::access(g, npc) = '.';
      return moved_npc;
   }

   return npc;
}

inline ll
p2 (vec<string> input)
{
   vec<string> input_warehouse;
   string input_moves;
   bool beforeemptyline = true;
   for (auto line : input) {
      if (beforeemptyline) beforeemptyline = !line.empty();
      if (beforeemptyline) input_warehouse.push_back(line);
      else input_moves.append(line);
   }

   for (auto& line : input_warehouse) {
      string_replace(line, string_view("."), string_view(".."));
      string_replace(line, string_view("#"), string_view("##"));
      string_replace(line, string_view("@"), string_view("@."));
      string_replace(line, string_view("O"), string_view("[]"));
   }

   auto g = grid::convert_to_grid<char>(input_warehouse);

   auto robot = grid::get_all_cells_with_value(g, '@')[0];

   for (auto move : input_moves) {
      auto dir = mzlib::convert<direction>(move);
      robot = move_dbl_npc(g, robot, dir);
   }

   return sr::fold_left(
      grid::get_all_cells_with_value(g, '[') | sv::transform([](auto it){ return it[0]+it[1]*100; }),
      0, std::plus()
      );
}

}
