#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "../../reusables/value_within_any_interval.h"
#include "../../reusables/get_interval_extremes.h"
#include "../../reusables/manhattan_distance.h"
#include <numeric>
#include <ranges>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace adventofcode2022::day15
{

/*
 *                 METHOD DECLARATIONS
 */

struct sensor {
   const mzlib::coordinates2d coor;
   const mzlib::coordinates2d beacon;
};

void
ys_covered_by_sensors (
   vector<pair<int, int>>& covered,
   vector<sensor>& sensors,
   int y_coor
)
{
   for (const auto& s: sensors)
   {
      const auto& sensor_distance_on_y = abs(y_coor - s.coor[1]);
      const auto& sensor_beacon_distance = manhattan_distance(s.coor, s.beacon);
      const auto& count = sensor_beacon_distance - sensor_distance_on_y;
      if (count <= 0)
         continue;
      const auto& start = s.coor[0] - count;
      covered.emplace_back(start, start + 2 * count);
   }
}

/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   vector<sensor> sensors;
   mzlib::copy_modify(input, sensors, [](const auto& e){
      auto a = mzlib::split(e, " =,:");
      return sensor{
         {stol(a[3].data()), stol(a[5].data())},
         {stol(a[11].data()), stol(a[13].data())},
      };
   });

   const long given_row = 2'000'000;

   vector<pair<int,int>> covered;
   ys_covered_by_sensors(covered, sensors, given_row);

   auto [min, max] = get_interval_extremes(covered);

   unordered_set<long> beacons_on_this_row;
   for(const auto& s : sensors)
      if(s.beacon[1]==given_row)
         beacons_on_this_row.insert(s.beacon[0]);

   int count = 0;
   for(int i=min; i<=max;++i)
      if(value_within_any_interval(covered, i) && !beacons_on_this_row.contains(i))
         ++count;

   // incorrect guesses: 6'349'685 too high, 4'725'497 too high
   return count;

}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   vector<sensor> sensors;
   mzlib::copy_modify(input, sensors, [](const auto& e){
      auto a = mzlib::split(e, " =,:");
      return sensor{
         {stol(a[3].data()), stol(a[5].data())},
         {stol(a[11].data()), stol(a[13].data())}
      };
   });

   vector<pair<int, int>> covered;
   for(int y_coor=0; y_coor<=4'000'000; ++y_coor)
   {
      ys_covered_by_sensors(covered, sensors, y_coor);

      for (int x_coor = 0; x_coor <= 4'000'000; ++x_coor)
      {
         bool in_range = false;
         for (const auto& c: covered)
            if (x_coor >= c.first && x_coor <= c.second)
            {
               in_range = true;
               x_coor = c.second;
               break;
            }
         if (!in_range)
            return (long)x_coor*(long)4'000'000 +(long)y_coor;
      }
      covered.clear();
   }

   return -1;
}




/*
 *                 METHOD DEFINITIONS
 */


/*
 *                 EXTRA
 */

namespace bonus
{

}

}
