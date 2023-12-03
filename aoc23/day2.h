#pragma once

#include "everything_bagel.h"

namespace aoc23::d2
{

inline ll
p1 (vec<string> input)
{
   map<string, ll> allowed = {
      {"red", 12},
      {"green", 13},
      {"blue", 14}
   };
   auto games = input;

   auto idsum = 0;
   for (auto game : games)
   {
      auto game_info = split(game, ":");
      auto game_id_part = split(game_info[0], " ");
      auto game_id_str = string(game_id_part[1]);
      auto game_id = stoll(game_id_str);
      auto sets = split(game_info[1], ";");

      bool game_has_invalid_set = false;
      for (auto set : sets)
      {
         auto cubes = split(set, ",");
         for(auto cube_colour : cubes)
         {
            auto colour = split(cube_colour, " ");
            auto colour_count = stoll(colour[0].data());
            auto colour_name = string(colour[1]);
            if(allowed[colour_name] < colour_count)
            {
               game_has_invalid_set = true;
            }
         }

      }
      if (!game_has_invalid_set)
      {
         idsum += game_id;
      }
   }

   return idsum;
}

inline ll
p2 (vec<string> input)
{
   auto games = input;

   auto powersum = 0;
   for (auto game : games)
   {
      auto game_info = split(game, ":");
      auto game_id_part = split(game_info[0], " ");
      auto game_id_str = string(game_id_part[1]);
      auto sets = split(game_info[1], ";");

      map<string, ll> minimum;
      for (auto set : sets)
      {
         auto cubes = split(set, ",");

         for(auto cube_colour : cubes)
         {
            auto colour = split(cube_colour, " ");
            auto colour_count = stoll(colour[0].data());
            auto colour_name = string(colour[1]);
            minimum[colour_name] = max(minimum[colour_name], colour_count);
         }
      }
      powersum += ::ranges::fold_left(minimum | std::views::values, 1, std::multiplies<>());
   }

   return powersum;
}

}
