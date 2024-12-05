#pragma once

#include <syncstream>

#include "everything_bagel.h"

namespace aoc24::d5
{

inline ll
p1 (vec<string> input)
{
   auto input_rules = std::views::filter(input, [](auto s){ return s.contains('|'); });
   auto input_updates= std::views::filter(input, [](auto s){ return s.contains(','); });

   map<string, set<string>> must_come_after;
   for (auto input_rule : input_rules) {
      vec<string> parts = absl::StrSplit(input_rule, absl::ByAnyChar("|"), absl::SkipEmpty());
      must_come_after[parts[0]].insert(parts[1]);
   }

   vec<vec<string>> updates;
   for (auto input_update : input_updates) {
      vec<string> update = absl::StrSplit(input_update, absl::ByAnyChar(","), absl::SkipEmpty());
      updates.push_back(update);
   }

   auto is_correctly_ordered = [&must_come_after](vec<string> update) {
      set<string> came_before;
      for ( auto num: update) {
         auto overlap = sets_intersection(came_before, must_come_after[num]);
         if (!overlap.empty()) return false;
         came_before.insert(num);
      }
      return true;
   };

   ll sum=0;
   for (auto update : updates)
      if (is_correctly_ordered(update))
         sum += stoll(update[update.size()/2]);

   return sum;
}

inline ll
p2 (vec<string> input)
{
   auto input_rules = std::views::filter(input, [](auto s){ return s.contains('|'); });
   auto input_updates= std::views::filter(input, [](auto s){ return s.contains(','); });

   map<string, set<string>> must_come_after;
   for (auto input_rule : input_rules) {
      vec<string> parts = absl::StrSplit(input_rule, absl::ByAnyChar("|"), absl::SkipEmpty());
      must_come_after[parts[0]].insert(parts[1]);
   }

   vec<vec<string>> updates;
   for (auto input_update : input_updates) {
      vec<string> update = absl::StrSplit(input_update, absl::ByAnyChar(","), absl::SkipEmpty());
      updates.push_back(update);
   }

   auto is_correctly_ordered = [&must_come_after](vec<string> update) {
      set<string> came_before;
      for ( auto num: update) {
         auto overlap = sets_intersection(came_before, must_come_after[num]);
         if (!overlap.empty()) return false;
         came_before.insert(num);
      }
      return true;
   };

   auto order_it = [&must_come_after](vec<string> update) {
      sr::sort(update, [&must_come_after](string prev, string next) {
         if (must_come_after[prev].contains(next))
            return true; // "true if the first argument is less", them's the rules
         return false;
      });
      return update;
   };

   ll sum=0;
   for (auto update : updates)
      if (!is_correctly_ordered(update)) {
         update = order_it(update);
         sum += stoll(update[update.size()/2]);
      }

   return sum;
}

}
