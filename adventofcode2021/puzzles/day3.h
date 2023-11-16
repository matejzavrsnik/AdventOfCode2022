#pragma once

#include "filesystem/read_write_file.h"
#include "../../reusables/binary_string_to_int.h"

namespace adventofcode2021::day3
{

std::string press_to_binary (int size, const std::vector<int>& count, char common, char uncommon, char tie);
std::vector<int> sum_bits (std::vector<std::string>& v);
std::string calc_g_rate (std::vector<std::string> v);
std::string calc_e_rate (std::vector<std::string> v);

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   auto g_rate = calc_g_rate(input);
   auto e_rate = calc_e_rate(input);
   auto i_g_rate = binary_string_to_int(g_rate);
   auto i_e_rate = binary_string_to_int(e_rate);

   return i_g_rate*i_e_rate;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   return 0;
}

inline std::vector<int>
sum_bits (std::vector<std::string>& v)
{
   std::vector<int> count;
   for(auto i=0; i<v[0].size(); ++i)
   {
      int bit_count=0;
      for (auto e: v)
         bit_count += e[i] - '0';
      count.push_back(bit_count);
   }
   return count;
}

inline std::string
press_to_binary (
   int size,
   const std::vector<int>& count,
   char common,
   char uncommon,
   char tie
)
{
   std::string rate;
   for(int i : count)
      rate += i>size/2
         ? common
         : i==size/2
            ? tie
            : uncommon;

   return rate;
}

inline std::string
calc_g_rate (std::vector<std::string> v)
{
   std::vector<int> count = sum_bits(v);

   std::string rate = press_to_binary(v.size(), count, '1', '0', '1');

   return rate;
}

inline std::string
calc_e_rate (std::vector<std::string> v)
{
   std::vector<int> count = sum_bits(v);

   std::string rate = press_to_binary(v.size(), count, '0', '1', '1');

   return rate;
}

namespace bonus
{

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   return 0;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file)[0];

   return 0;
}

}

}