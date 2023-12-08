#pragma once

#include "everything_bagel.h"

namespace aoc23::d5
{

struct range { ll dest; ll src; ll len; };

inline ll
find(
   vec<range>& ranges,
   ll seed)
{
   auto the_range = ranges
      | ranges::views::filter([&seed](auto r) { return r.src <= seed && r.src+r.len > seed; })
      | ranges::to<vec<range>>;

   if(the_range.size() > 1)
   {
      cout << "die" << endl;
      std::terminate();
   }

   if(the_range.size() == 1)
   {
      ll diff = the_range[0].dest - the_range[0].src;
      return seed + diff;
   }

   return seed;
}

inline ll
p1 (vec<string> input)
{
   set<ll> seeds;
   string current_map;
   map<string, vec<range>> maps;
   for(auto line : input)
   {
      if (line.length() == 0)
         continue;

      auto by_colon = split(line, ":");
      if(by_colon.size() > 1 && by_colon[0] == "seeds") // "seeds: 41218238 421491713"
      {
         auto seeds_str = split(by_colon[1], " ");
         seeds = seeds_str | ranges::views::transform(strv_to_ll) | ranges::to<set<ll>>;
      }
      else if(line.contains("map")) // "seed-to-soil map:"
      {
         current_map = split(line, " ")[0];
      }
      else // "1389477588 1222450723 86190269"
      {
         auto range_str = split(line, " ");
         maps[current_map].push_back(
            range {
               .dest=strv_to_ll(range_str[0]),
               .src=strv_to_ll(range_str[1]),
               .len=strv_to_ll(range_str[2]),
            });
      }
   }

   // sort ranges by source
   for(auto& m : maps)
      absl::c_sort(m.second, [](auto l, auto r){ return (l.src < r.src); });

   ll min_location = max_ll;
   for(auto seed : seeds)
   {
      auto soil = find(maps["seed-to-soil"], seed);
      auto fertilizer = find(maps["soil-to-fertilizer"], soil);
      auto water = find(maps["fertilizer-to-water"], fertilizer);
      auto light = find(maps["water-to-light"], water);
      auto temperature = find(maps["light-to-temperature"], light);
      auto humidity = find(maps["temperature-to-humidity"], temperature);
      auto location = find(maps["humidity-to-location"], humidity);

      min_location = min(min_location, location);
   }

   return min_location;
}

inline ll
find_src(
   const vec<range>& ranges,
   ll dest)
{
   for(const auto& the_range : ranges)
      if(the_range.dest <= dest && the_range.dest+the_range.len > dest)
   {
      ll dest_advance = dest - the_range.dest;
      return the_range.src + dest_advance;
   }

   return dest;
}

bool is_a_given_seed(const vec<ll>& seeds, ll seed)
{
   for(int i=0; i<seeds.size(); i+=2)
      if(seeds[i] <= seed && seed < seeds[i]+seeds[i+1])
         return true;
   return false;
}

inline ll
p2 (vec<string> input)
{
   vec<ll> seeds;
   string current_map;
   umap<string, vec<range>> maps;
   for(auto line : input)
   {
      if (line.length() == 0)
         continue;

      auto by_colon = split(line, ":");
      if(by_colon.size() > 1 && by_colon[0] == "seeds") // "seeds: 41218238 421491713"
      {
         auto seeds_str = split(by_colon[1], " ");
         seeds = seeds_str | ranges::views::transform(strv_to_ll) | ranges::to<vec<ll>>;
      }
      else if(line.contains("map")) // "seed-to-soil map:"
      {
         current_map = split(line, " ")[0];
      }
      else // "1389477588 1222450723 86190269"
      {
         auto range_str = split(line, " ");
         maps[current_map].push_back(
            range {
               .dest=strv_to_ll(range_str[0]),
               .src=strv_to_ll(range_str[1]),
               .len=strv_to_ll(range_str[2]),
            });
      }
   }

   // sort ranges by dest
   for(auto& m : maps)
      absl::c_sort(m.second, [](auto l, auto r){ return (l.dest < r.dest); });

   for(const auto location : ranges::views::iota(0, 9999999999))
   {
      auto humidity  = find_src(maps["humidity-to-location"], location);
      auto temperature  = find_src(maps["temperature-to-humidity"], humidity);
      auto light  = find_src(maps["light-to-temperature"], temperature);
      auto water  = find_src(maps["water-to-light"], light);
      auto fertilizer  = find_src(maps["fertilizer-to-water"], water);
      auto soil  = find_src(maps["soil-to-fertilizer"], fertilizer);
      auto seed = find_src(maps["seed-to-soil"], soil);

      if(is_a_given_seed(seeds, seed))
         return location;

   }

   return -1;
}

}
