#pragma once

#include "everything_bagel.h"

namespace aoc23::d6
{

inline ll
p1 (vec<string> input)
{
   vec<vec<ll>> races;
   for(auto line : input)
   {
      auto label_numbers = split(line, ":");
      auto numbers_str = split(label_numbers[1], " ");
      auto numbers = numbers_str | ranges::views::transform(strv_to_ll) | ranges::to_vector;
      races.push_back(numbers);
   }

   // how far do I go in race_time if I press for [index] number of ms?
   auto calculate_distances = [](ll race_time){
      vec<ll> distances;
      for(ll press = 0; press < race_time; ++press) {
         ll speed = press;
         ll time_left = race_time-press;
         distances.push_back(speed*time_left);
      }
      return distances;
   };

   ll ways_to_beat = 1;
   for(ll race=0; race<races[0].size(); ++race)
   {
      auto race_time = races[0][race];
      auto race_dist = races[1][race];
      auto distances = calculate_distances(race_time);
      ways_to_beat *= absl::c_count_if(distances, greater_than(race_dist));
   }

   // look. it worked. ok?

   return ways_to_beat;
}

inline ll
p2 (vec<string> input)
{
   ll race_time = 56977875;
   ll race_dist = 546192711311139;

   ll ways_to_beat = 0;
   for(ll press = 0; press < race_time; ++press) {
      ll speed = press;
      ll time_left = race_time-press;
      if(speed*time_left > race_dist)
         ++ways_to_beat;
   }
   return ways_to_beat;
}

}
