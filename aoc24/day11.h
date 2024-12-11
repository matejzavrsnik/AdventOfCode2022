#pragma once

#include "everything_bagel.h"

namespace aoc24::d11
{

pair<string, string>
split_number(string number) {
   int half_way = number.size()/2;
   auto left = number.substr(0, half_way);
   auto right = number.substr(half_way, number.size());
   return {left, right};
}

void
blink (vec<ll>& stones) {
   for (int i=0; i<stones.size(); ++i) {
      auto stone_str = std::to_string(stones[i]);
      if (stones[i]==0) stones[i]=1;
      else if (stone_str.size()%2==0) {
         auto [left, right] = split_number(stone_str);
         stones.insert(stones.begin()+i, 0);
         stones[i]=stoll(left);
         stones[++i]=stoll(right);
      }
      else stones[i]*=2024;
   }
}

inline ll
p1 (vec<string> input)
{
   vec<ll> stones = split(input[0], " ")
      | sv::transform(strv_to_ll)
      | sr::to<vec<ll>>();

   for (int count=0; count<25; ++count)
      blink(stones);

   return stones.size();
}

vec<ll>
blink_one_stone(ll stone) {
   if (stone==0) return {1};

   auto stone_str = std::to_string(stone);
   if (stone_str.size()%2==0) {
      auto [left, right] = split_number(stone_str);
      return {stoll(left), stoll(right)};
   }

   return {stone*2024};
}

// 0,10x =
// blink(0): 1,9x =
// blink(1): 2024,8x =
// blink(2024): 20,7x + 23,7x
ll blink2(const ll stone, const int count) {
   static map<pair<ll, int>, ll> memo;

   if (count==0)
      return 1;

   if (!memo.contains({stone, count}))
      for (auto b : blink_one_stone(stone))
         memo[{stone, count}] += blink2(b, count-1);

   return memo[{stone, count}];
}

inline ll
p2 (vec<string> input) {
   return sr::fold_left(
      split(input[0], " ")
      | sv::transform(strv_to_ll)
      | sv::transform([] (auto stone) { return blink2(stone, 75); }),
      0, std::plus());
}

}
