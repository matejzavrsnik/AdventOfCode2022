#pragma once

#include "everything_bagel.h"

namespace aoc24::d1 {
inline ll
p1 (vec<string> input) {
   auto nums = numbers_in_columns<ll, 2>(input);

   absl::c_sort(nums[0]);
   absl::c_sort(nums[1]);

   return
      sr::fold_left(
         sv::zip_transform(
            abs_minus<ll>,
            nums[0],
            nums[1]),
         0, std::plus());
}

inline ll
p2 (vec<string> input) {
   auto nums = numbers_in_columns<ll, 2>(input);

   auto count_fun = [&nums] (ll num) {
      return absl::c_count(nums[1], num);
   };

   return
      sr::fold_left(
         sv::zip_transform(
            std::multiplies(),
            nums[0],
            nums[0] | sv::transform(count_fun)
         ),
         0, std::plus());
}
}
