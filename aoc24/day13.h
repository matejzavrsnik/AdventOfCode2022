#pragma once

#include <gmock/gmock-matchers.h>

#include "everything_bagel.h"

namespace aoc24::d13
{

inline ll minimum_tokens(const cell& a, const cell& b, const cell& prize) {
   ll tokens = max_ll;
   for (ll amoves=0; amoves<100; ++amoves) {
      cell claw = a*amoves;
      auto distance_left = prize-claw;
      if (distance_left[0]%b[0]==0 && distance_left[1]%b[1]==0) {
         ll bmoves = distance_left[0]/b[0];
         if (claw+b*bmoves == prize)
            if (amoves*3+bmoves*1 < tokens)
               tokens = amoves*3+bmoves;
      }
   }
   return tokens;
}

inline ll
p1 (vec<string> input)
{
   auto parse = [](auto it) {
      vec<string> partsa = absl::StrSplit(it[0], absl::ByAnyChar(" :+,="), absl::SkipEmpty());
      vec<string> partsb = absl::StrSplit(it[1], absl::ByAnyChar(" :+,="), absl::SkipEmpty());
      vec<string> prize = absl::StrSplit(it[2], absl::ByAnyChar(" :+,="), absl::SkipEmpty());
      return std::tuple{
         cell{stoll(partsa[3]), stoll(partsa[5])},
         cell{stoll(partsb[3]), stoll(partsb[5])},
         cell{stoll(prize[2]), stoll(prize[4])}
      };
   };

   auto tokens = sr::fold_left(
      input
         | sv::chunk(4)
         | sv::transform(parse)
         | sv::transform([](auto it) {
            return minimum_tokens(std::get<0>(it), std::get<1>(it), std::get<2>(it));
         })
         | sv::filter([](auto it) {
            return it != max_ll;
         }),
      0, std::plus());

   return tokens;

}

inline ll
p2 (vec<string> input)
{

   return 0;
}

}
