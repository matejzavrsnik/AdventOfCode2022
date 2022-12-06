#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"

namespace adventofcode2021::day2
{

long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   long p=0, d=0;
   for(auto in : input) {
      auto split = mzlib::split(in, " ");
      if(split[0] == "up") d-=std::stoi(split[1].data());
      if(split[0] == "down") d+=std::stoi(split[1].data());
      if(split[0] == "forward") p+=std::stoi(split[1].data());
   }

   return p*d;
}

long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   long p=0, d=0, aim=0;
   for(auto in : input) {
      auto split = mzlib::split(in, " ");
      if(split[0] == "up") aim-=std::stoi(split[1].data());
      if(split[0] == "down") aim+=std::stoi(split[1].data());
      if(split[0] == "forward") {
         p+=std::stoi(split[1].data());
         d+=aim*std::stoi(split[1].data());
      }
   }

   return p*d;
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