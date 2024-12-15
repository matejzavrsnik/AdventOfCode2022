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
            // a, b, prize
            auto a = std::get<0>(it);
            auto b = std::get<1>(it);
            auto p = std::get<2>(it);

            // 1) n*a0 + m*b0 = p0
            // 2) n*a1 + m*b1 = p1

            // solve for n from 1):
            // n*a0 = p0 - m*b0
            // n = (p0 - m*b0) / a0

            // use n from 1) into 2) and derive m:
            // ((p0 - m*b0) / a0) * a1 + m*b1 = p1
            // (p0/a0 - (m*b0)/a0) * a1 + m*b1 = p1
            // (p0*a1)/a0 - (m*b0*a1)/a0 + m*b1 = p1
            // (m*b0*a1)/a0 + m*b1 = p1  - (p0*a1)/a0
            // m*b0*a1 + m*b1*a0 = p1*a0  - p0*a1
            // m*(b0*a1 + b1*a0)  = p1*a0  - p0*a1
            // m = (p1*a0 - p0*a1)/(b0*a1 + b1*a0)

            auto m = (p[1]*a[0] - p[0]*a[1]) / (b[0]*a[1] + b[1]*a[0]);
            auto n = (p[0] - m*b[0]) / a[0];

            auto result = n+3*m;

            // 1) n*a0 + m*b0 = p0
            // 2) n*a1 + m*b1 = p1

            // to equal zero
            // 1) n*a0 + m*b0 - p0 = 0
            // 2) n*a1 + m*b1 - p1 = 0

            // now both 1) and 2) are equal
            // n*a0 + m*b0 - p0 = n*a1 + m*b1 - p1
            // see if I can pull out n
            // n*a0 - n*a1 = m*b1 - p1 - m*b0 + p0
            // n*(a0-a1) = m*b1 - p1 - m*b0 + p0
            // n = (m*b1 - p1 - m*b0 + p0) / (a0-a1)
            // n = (m*b1 - m*b0 + p0 - p1) / (a0-a1)
            // NOPE

            //Button A: X+94, Y+34
            //Button B: X+22, Y+67
            //Prize: X=8400, Y=5400
            // n94+m22=8400 => m22=8400-n94 => m=(8400-n94)/22
            // n34+m67=5400
            //   => n34+((8400-n94)/22)*67=5400
            //   =>

            n = (p[0]*b[1]-b[0]*p[1]) / (a[0]*b[1]-b[0]*a[1]);
            m = (a[0]*p[1]-p[0]*a[1]) / (a[0]*b[1]-b[0]*a[1]);
            result = n+3*m;
            return result;
         })
         | sv::filter([](auto it) {
            cout << it << endl;
            return it != max_ll;
         }),
      0, std::plus());

   return tokens;


}

}
