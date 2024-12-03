#pragma once

#include "everything_bagel.h"

namespace aoc24::d3
{

inline ll
p1 (vec<string> input)
{
   std::regex pattern("mul\\([0-9]{1,3},[0-9]{1,3}\\)");

   vec<string> muls;
   for (auto line : input) {
      for (std::smatch pattern_match; std::regex_search(line, pattern_match, pattern);) {
         muls.push_back(pattern_match.str());
         line = pattern_match.suffix();
      };
   }

   vec<pair<ll,ll>> nums;
   for (auto mul : muls) {
      vec<string> parts = absl::StrSplit(mul, absl::ByAnyChar("(,)"), absl::SkipEmpty());
      nums.push_back(std::make_pair(stoll(parts[1]), stoll(parts[2])));
      int i=0;
   }

   // why no work?
   // vec<string> a = {"a,b,d,s"}
   // a | std::ranges::transform(split)

   ll sum = 0;
   for (auto num : nums) {
      sum += num.first*num.second;
   }

   return sum;
}

inline ll
p2 (vec<string> input)
{

   string mul_pattern("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
   string do_pattern("do\\(\\)");
   string dont_pattern("don't\\(\\)");
   std::regex pattern(mul_pattern+"|"+do_pattern+"|"+dont_pattern);

   vec<string> muls;
   bool do_mul = true;
   for (auto line : input) {
      for (std::smatch pattern_match; std::regex_search(line, pattern_match, pattern);) {
         auto token = pattern_match.str();

         if (token == "don't()") do_mul = false;
         else if (token == "do()") do_mul = true;
         else if (do_mul) muls.push_back(pattern_match.str());

         line = pattern_match.suffix();
      };
   }

   vec<pair<ll,ll>> nums;
   for (auto mul : muls) {
      vec<string> parts = absl::StrSplit(mul, absl::ByAnyChar("(,)"), absl::SkipEmpty());
      nums.push_back(std::make_pair(stoll(parts[1]), stoll(parts[2])));
      int i=0;
   }

   // why no work?
   // vec<string> a = {"a,b,d,s"}
   // a | std::ranges::transform(split)

   ll sum = 0;
   for (auto num : nums) {
      sum += num.first*num.second;
   }

   return sum;
}

}
