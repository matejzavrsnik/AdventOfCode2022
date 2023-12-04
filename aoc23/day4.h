#pragma once

#include "everything_bagel.h"

namespace aoc23::d4
{

inline ll
p1 (vec<string> input)
{
   ll sum_points = 0;
   for(auto line : input)
   {
      auto card_info = split(line, ":");
      auto card_numbers = split(card_info[1], "|");
      auto winning_str = split(card_numbers[0], " ");
      auto having_str = split(card_numbers[1], " ");

      auto winning_set = winning_str
         | ranges::views::transform(strview_to_ll)
         | ranges::to<set<ll>>;

      auto having_set = having_str
         | ranges::views::transform(strview_to_ll)
         | ranges::to<set<ll>>;

      auto have_winning = ranges::distance(
         ranges::views::set_intersection(
            winning_set,
            having_set));

      if(have_winning > 0)
         sum_points += std::pow(2, have_winning-1);
   }

   return sum_points;
}

inline ll
p2 (vec<string> input)
{
   vec<ll> card_copies_tally(input.size(), 1);
   for(int i =0; i<input.size(); ++i)
   {
      auto line = input[i];
      auto card_info = split(line, ":");
      auto card_numbers = split(card_info[1], "|");
      auto winning_str = split(card_numbers[0], " ");
      auto having_str = split(card_numbers[1], " ");

      auto winning_set = winning_str
         | ranges::views::transform(strview_to_ll)
         | ranges::to<set<ll>>;

      auto having_set = having_str
         | ranges::views::transform(strview_to_ll)
         | ranges::to<set<ll>>;

      auto have_winning = ranges::distance(
         ranges::views::set_intersection(
            winning_set,
            having_set));

      for(int j=i+1; j<i+1+have_winning; ++j)
         card_copies_tally[j] += card_copies_tally[i];
   }

   return ranges::accumulate(card_copies_tally, 0, std::plus());
}

}
