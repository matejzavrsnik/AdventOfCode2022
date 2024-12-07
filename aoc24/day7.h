#pragma once

#include "everything_bagel.h"

namespace aoc24::d7
{

template<typename It>
int solve_ce(ll final_result, ll partial_result, It begin, It end) {

   if (final_result<partial_result) return 0; // not a way

   int ways = 0;
   auto next = *begin;
   if (begin+1 == end) { // last case
      if (partial_result+next == final_result) ++ways;
      if (partial_result*next == final_result) ++ways;
   }
   else {
      ways += solve_ce(final_result, try_add(partial_result,next), begin+1, end);
      ways += solve_ce(final_result, try_mul(partial_result, next), begin+1, end);
   }
   return ways;
}

inline ll
p1 (vec<string> input) {

   vec<vec<ll>> calibration_equations;
   for (auto line : input) {
      vec<string> parts_s = absl::StrSplit(line, absl::ByAnyChar(": "), absl::SkipEmpty());
      vec<ll> parts_ll = parts_s | std::views::transform(str_to_ll) | std::ranges::to<vec<ll>>();
      calibration_equations.push_back(parts_ll);
   }

   ll sum = 0;
   for (auto ce : calibration_equations) {
      ll ways = solve_ce(ce[0], 0, ce.begin()+1, ce.end());
      if (ways > 0)
         sum += ce[0];
   }

   return sum;
}

template<typename It>
bool solve_ce2(ll final_result, ll partial_result, It begin, It end, int level = 0) {
   if (final_result<partial_result) return 0; // not a way

   auto next = *begin;

   if (begin+1 == end) { // last case
      if (partial_result+next == final_result) {
         //cout<<ind(level)<<partial_result<<"+"<<next<<" win"<<endl;
         return true;
      }
      //else { cout<<ind(level)<<partial_result<<"+"<<next<<" no"<<endl;}
      if (partial_result*next == final_result) {
         //cout<<ind(level)<<partial_result<<"*"<<next<<" win"<<endl;
         return true;
      }
      //else { cout<<ind(level)<<partial_result<<"*"<<next<<" no"<<endl;}
      auto glued = str_to_ll(std::to_string(partial_result)+std::to_string(next));
      if (glued == final_result) {
         //cout<<ind(level)<<partial_result<<"|"<<glued<<" win"<<endl;
         return true;
      }
      //else { cout<<ind(level)<<"|"<<glued<<" no"<<endl;}
   }
   else {
      //cout<<ind(level)<<partial_result<<"+"<<next<<"="<<try_add(partial_result,next)<<endl;
      bool solved = solve_ce2(final_result, try_add(partial_result,next), begin+1, end, level+1);
      if (solved) return true;


      if (partial_result>0) { // no point mul with 0
         //cout<<ind(level)<<partial_result<<"*"<<next<<"="<<try_mul(partial_result, next)<<endl;
         solved = solve_ce2(final_result, try_mul(partial_result, next), begin+1, end, level+1);
      }
      if (solved) return true;

      if (partial_result>0) { // no point concat with 0 in front
         partial_result = str_to_ll(std::to_string(partial_result)+std::to_string(next));
         //cout<<ind(level)<<"|("<<partial_result<<")"<<endl;
         solved = solve_ce2(final_result, partial_result, begin+1, end, level+1);
         if (solved) return true;
      }
   }
   return false;
}

inline ll
p2 (vec<string> input)
{
   vec<vec<ll>> calibration_equations;
   for (auto line : input) {
      vec<string> parts_s = absl::StrSplit(line, absl::ByAnyChar(": "), absl::SkipEmpty());
      vec<ll> parts_ll = parts_s | std::views::transform(str_to_ll) | std::ranges::to<vec<ll>>();
      calibration_equations.push_back(parts_ll);
   }

   ll sum = 0;
   for (auto ce : calibration_equations) {
      //cout << "------" << endl;
      //mzlib::print(ce);
      bool solved = solve_ce2(ce[0], 0, ce.begin()+1, ce.end());
      if (solved)
         sum += ce[0];
   }

   return sum;
}

}
