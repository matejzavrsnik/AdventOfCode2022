#pragma once

#include "filesystem/read_write_file.h"

// part 1 solution
long start_packet_marker(std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   const auto window_size = 4;
   auto cursor = input.begin()+window_size-1;
   std::set<char> window;
   do
   {
      window.clear();
      auto window_end = ++cursor;
      auto window_start = cursor-window_size;
      window.insert(window_start, window_end);
   }
   while(window.size() < window_size);

   return std::distance(input.begin(), cursor);
}

// part 2 solution
long start_message_marker(std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   const auto window_size = 14;
   auto cursor = input.begin()+window_size-1;
   std::set<char> window;
   do
   {
      window.clear();
      auto window_end = ++cursor;
      auto window_start = cursor-window_size;
      window.insert(window_start, window_end);
   }
   while(window.size() < window_size);

   return std::distance(input.begin(), cursor);
}

namespace bonus
{



}
