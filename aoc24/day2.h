#pragma once

#include "everything_bagel.h"

namespace aoc24::d2
{
inline ll
p1 (vec<string> input) {
   ll count_safe = 0;
   for (auto report : input) {
      ll direction = 0;
      auto safe_level = sr::all_of(
         split(report, " ")
         | sv::transform(strv_to_ll)
         | std::views::adjacent<2>
         | sv::transform([&direction] (auto tup) {
            auto [prev, next] = tup;
            if (prev == next) return false; /// unsafe
            if (direction == 0) direction = (next - prev) / std::abs(next - prev);
            bool safe = direction == 1
                        ? (next > prev && next <= (prev + 3))
                        : (next < prev && next >= (prev - 3));
            return safe;
         }),
         [] (auto safe) { return safe == true; });

      if (safe_level) ++count_safe;
   }
   return count_safe;
}

inline ll
p2 (vec<string> input)
{
   return 0;
}

}
