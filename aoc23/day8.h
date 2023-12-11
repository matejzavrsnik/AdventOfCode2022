#pragma once

#include "everything_bagel.h"

namespace aoc23::d8
{

inline ll
p1 (vec<string> input)
{
   string instructions = *input.begin();
   input.erase(input.begin(), input.begin()+2);

   umap<string, pair<string, string>> paths;
   for(auto line : input)
   {
      vec<string> parts = absl::StrSplit(line, absl::ByAnyChar(" =(,)"), absl::SkipEmpty()); // FJT = (XDJ, LQV)
      paths[parts[0]] = {parts[1], parts[2]};
   }

   auto cycle = instructions | ranges::views::cycle;
   auto instruction_it = cycle.begin();
   string node = "AAA";
   int steps = 0;

   while(node != "ZZZ") {
      node = *instruction_it++ == 'L' ? paths[node].first : paths[node].second;
      ++steps;
   }

   return steps;
}

template<typename Container>
opt<pair<typename Container::iterator, typename Container::iterator>>
find_repeated_pattern(
   Container& c,
   typename Container::iterator pattern_start)
{
   ll pattern_length = 2;
   auto pattern_end = pattern_start+pattern_length;
   vec<typename Container::iterator> occurrences;
   do
   {
      occurrences = find_subsequence(c.begin(), c.end(), pattern_start, pattern_end);

      if(occurrences.size() < 2)
         return nullopt; // no pattern starting at `pattern_start`

      auto& first_repeat = occurrences[1];
      if (pattern_end == first_repeat)
         return make_pair(pattern_start, pattern_end);
      else
      {
         pattern_length = distance(pattern_start, first_repeat);
         pattern_end = pattern_start+pattern_length;
      }
   }
   while(true);

   return nullopt; // Should Never Happen™
}

template<typename Container>
Container convert_to_differentials(const Container& c)
{
   Container copy = c;
   for(ll i=0; i<copy.size()-1; ++i)
      copy[i] = copy[i+1]-copy[i];
   return copy;
}

inline ll
p2 (vec<string> input)
{
   string instructions = *input.begin();
   input.erase(input.begin(), input.begin()+2);

   umap<string, pair<string, string>> paths;
   vec<string> all_start_nodes;
   for(auto line : input)
   {
      vec<string> parts = absl::StrSplit(line, absl::ByAnyChar(" =(,)"), absl::SkipEmpty()); // FJT = (XDJ, LQV)
      paths[parts[0]] = {parts[1], parts[2]};
      if(parts[0][2] == 'A')
         all_start_nodes.push_back(parts[0]);
   }

   auto cycle = instructions | ranges::views::cycle;
   auto instruction_it = cycle.begin();

   auto ghosts_positions = all_start_nodes;
   vec<vec<ll>> goal_reaches(ghosts_positions.size(), vec<ll>());

   ll steps_so_far = 0;
   ll ghost_to_reach_goal_count = 10;

   // repeat until each ghost reached goal N times
   while(absl::c_any_of(goal_reaches,
      [&](const vec<ll>& this_ghost_goal_reached) {
         return this_ghost_goal_reached.size() < ghost_to_reach_goal_count;
      }))
   {
      auto next_instruction = *instruction_it++;
      ++steps_so_far;
      // every ghost to make next step
      for (ll ghost = 0; ghost < ghosts_positions.size(); ++ghost)
      {
         // if ghost already reached goal N times, don't bother
         if(goal_reaches[ghost].size() >= ghost_to_reach_goal_count)
            continue;
         // make step
         ghosts_positions[ghost] = next_instruction == 'L'
            ? paths[ghosts_positions[ghost]].first
            : paths[ghosts_positions[ghost]].second;
         // is this goal position?
         if (ghosts_positions[ghost][2] == 'Z')
            goal_reaches[ghost].push_back(steps_so_far);
      }
   }

   return ranges::fold_left(
      goal_reaches
         | ranges::views::transform([](vec<ll>& r) {
            auto r_diff = convert_to_differentials(r);
            return r_diff[0];
         }),
      1,
      std::lcm<ll,ll>);
}

}
