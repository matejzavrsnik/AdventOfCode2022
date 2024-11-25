#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"

using namespace std;

namespace adventofcode2022::day16
{

/*
 *                 METHODS
 */

struct valve
{
   string name;
   int flow;
   vector<string> leading_to;
   bool open = false;
};

bool all_valves_closed(const unordered_map<string, valve>& valves_map)
{
   return valves_map.end() == find_if(
      valves_map.begin(), valves_map.end(),
      [](auto a){
         return (!a.second.open && a.second.flow>0);
      });
}

int one_minute_of_activity(
   unordered_map<string, valve> valves_map,
   int current_minute,
   string current_valve,
   string came_from,
   int total_pressure_released,
   int per_min_pressure_release)
{
   const int available_time = 30;
   cout << endl << std::string(current_minute, '.') << "at " << current_valve << "|";

   if(++current_minute == available_time) // shrinking of problem
   {
      cout << "finish (time) " << total_pressure_released << "|";
      return total_pressure_released; // end clause
   }

   if (all_valves_closed(valves_map))
   {
      cout << "finish (done) " << total_pressure_released << "|";
      return total_pressure_released+((available_time-current_minute)*per_min_pressure_release); // end clause
   }

   // each open valve adds to released pressure this minute no matter what I do
   total_pressure_released += per_min_pressure_release;

   // two things I can do once here
   auto valves_map_copy1 = valves_map;
   auto valves_map_copy2 = valves_map; // don't strictly need the second copy, but avoiding confusion
   set<int> possible_futures{0};

   // I can either open a closed valve
   if (valves_map_copy1[current_valve].flow > 0 && !valves_map_copy1[current_valve].open)
   {
      cout << current_valve << " opening|";
      valves_map_copy1[current_valve].open = true;
      per_min_pressure_release += valves_map_copy1[current_valve].flow;
      auto future1 = one_minute_of_activity(
         valves_map_copy1,
         current_minute,
         current_valve,
         came_from,
         total_pressure_released,
         per_min_pressure_release);
      possible_futures.insert(future1);
   }

   // or I can go to other places
   for(const auto& next_valve : valves_map_copy2[current_valve].leading_to)
   {
      if (came_from == next_valve && (valves_map_copy1[next_valve].flow == 0 || valves_map_copy1[current_valve].open))
         continue; // no point in going back, would just waste a minute

      cout << next_valve << " going|";
      auto future2 = one_minute_of_activity(
         valves_map_copy2,
         current_minute,
         next_valve,
         current_valve,
         total_pressure_released,
         per_min_pressure_release);
      possible_futures.insert(future2);
   }

   cout << " max=" << *possible_futures.rbegin() << "|";

   // which of these options released most pressure?
   return *possible_futures.rbegin(); // return max
}

/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   vector<valve> valves;
   mzlib::copy_modify(input, valves, [](const auto& e){
      auto s = mzlib::split(e, " ,;=");
      valve v;
      v.name=s[1];
      v.flow=stoi(s[5].data());
      for(int n=10; n<s.size(); ++n)
         v.leading_to.push_back(string(s[n]));
      return v;
   });

   unordered_map<string, valve> valves_map;
   for(const auto& v : valves)
      valves_map[v.name] = v;

   int current_minute = 0;
   string current_valve = "AA";
   int total_pressure_released = 0;
   int per_min_pressure_release = 0;

   // I was being naive. This implementation is way too slow.
   //total_pressure_released = one_minute_of_activity(
   //   valves_map,
   //   current_minute,
   //   current_valve,
   //   "",
   //   total_pressure_released,
   //   per_min_pressure_release);

   return total_pressure_released;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   /*
   TYPE converted;
   mzlib::copy_modify(input, converted, [](const auto& e){
      return CONVERSION;
   });
    */

   return -1;
}

}