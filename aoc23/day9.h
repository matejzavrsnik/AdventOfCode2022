#pragma once

#include "everything_bagel.h"

namespace aoc23::d9
{

template<typename Container>
Container convert_to_differentials(const Container& c)
{
   Container copy;
   for(ll i=0; i<c.size()-1; ++i)
      copy.push_back(c[i+1]-c[i]);
   return copy;
}

template<typename Container>
vec<Container> differentiate(const Container& c)
{
   vec<Container> diffs;
   diffs.push_back(c);

   while(!absl::c_all_of(diffs.back(), equal_to(0)))
   {
      Container c_diff = convert_to_differentials(diffs.back());
      diffs.push_back(c_diff);
   }
   return diffs;
}

template<typename Container>
vec<Container> extrapolate(const vec<Container>& c)
{
   vec<Container> extrapolated = c;
   extrapolated.back().push_back(0);

   //auto result = extrapolated
   //   | ranges::views::reverse
   //   | ranges::views::sliding(2)
   //   | ranges::views::transform( [](auto e) {
   //         e[1].push_back(e[1].back()+e[0].back());
   //         return e[1];
   //      })
   //   | ranges::views::reverse
   //   | ranges::to_vector;
   for(int i=extrapolated.size()-2; i>=0; --i) {
      extrapolated[i].push_back( extrapolated[i+1].back() + extrapolated[i].back() );
   }

   return extrapolated;
}

vec<vec<ll>> extrapolate_front(const vec<vec<ll>>& c)
{
   vec<vec<ll>> extrapolated = c;

   for(int i=extrapolated.size()-2; i>=0; --i) {
      extrapolated[i].insert(extrapolated[i].begin(), extrapolated[i].front() - extrapolated[i+1].front() );
   }

   return extrapolated;
}

inline ll
p1 (vec<string> input)
{
   vec<vec<ll>> input_sequences;
   for(auto line : input)
   {
      vec<string> sequence_str = absl::StrSplit(line, absl::ByAnyChar(" "), absl::SkipEmpty());
      vec<ll> sequence_ll = sequence_str | ranges::views::transform(str_to_ll) | ranges::to_vector;
      input_sequences.push_back(sequence_ll);
   }

   vec<ll> extrapolated_values;
   for(auto input_sequence : input_sequences) {
      auto differentiated = differentiate(input_sequence);
      auto extrapolated = extrapolate(differentiated);
      extrapolated_values.push_back(extrapolated.front().back());
   }

   return absl::c_accumulate(extrapolated_values, 0);
}

inline ll
p2 (vec<string> input)
{
   vec<vec<ll>> input_sequences;
   for(auto line : input)
   {
      vec<string> sequence_str = absl::StrSplit(line, absl::ByAnyChar(" "), absl::SkipEmpty());
      vec<ll> sequence_ll = sequence_str | ranges::views::transform(str_to_ll) | ranges::to_vector;
      input_sequences.push_back(sequence_ll);
   }

   vec<ll> extrapolated_values;
   for(auto input_sequence : input_sequences) {
      auto differentiated = differentiate(input_sequence);
      auto extrapolated = extrapolate_front(differentiated);
      extrapolated_values.push_back(extrapolated.front().front());
   }

   return absl::c_accumulate(extrapolated_values, 0);
}

}
