#pragma once

#include <stack>
#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "tools/sort_map_by_value.h"

namespace adventofcode2022::day7
{

using path = std::vector<std::string_view>;

std::map<path, int> get_sizes (std::vector<std::string>& input);

long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::map<path, int> sizes = get_sizes(input);

   return std::accumulate(sizes.begin(), sizes.end(), 0, [](auto sum, auto p){
      if(p.second<=100000)
         sum+=p.second;
      return sum;
   });
}

long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::map<path, int> sizes = get_sizes(input);

   auto sorted = mzlib::sort_map_by_value(sizes);

   const int disk_size = 70000000;
   const int needed = 30000000;
   const int data_size = sizes[{"/"}];
   const int need_delete = needed-disk_size+data_size;

   return std::find_if(sorted.begin(), sorted.end(), [need_delete](auto e){
      return e.second >= need_delete;
   })->second;
}

std::map<path, int>
get_sizes (std::vector<std::string>& input)
{
   path current;
   std::map<path, int> sizes;
   enum class command {none, cd, ls} command = command::none;

   for(const auto& in : input)
   {
      auto s = mzlib::split(in, " ");
      if (s[0]=="$")
      {
         if (s[1] == "cd")
         {
            command = command::cd;
            if (s[2] == "/")
               current = {"/"};
            else if (s[2] == "..")
               current.pop_back();
            else
               current.push_back(s[2]);
         }
         else if (s[1] == "ls")
         {
            command = command::ls;
         }
      }
      else if(command == command::ls)
      {
         if(s[0]!="dir")
         {
            auto current_copy = current;
            while(!current_copy.empty())
            {
               sizes[current_copy] += std::stoi(s[0].data());
               current_copy.pop_back();
            }
         }
      }
   }
   return sizes;
}

namespace bonus
{

long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   return 0;
}

long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   return 0;
}

}

}