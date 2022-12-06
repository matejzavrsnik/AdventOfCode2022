#pragma once

#include "filesystem/read_write_file.h"

namespace adventofcode2021::day3
{

std::string press_to_binary (int size, const std::vector<int>& count, char common, char uncommon, char tie);
std::vector<int> sum_bits (std::vector<std::string>& v);
std::string calc_g_rate (std::vector<std::string> v);
std::string calc_e_rate (std::vector<std::string> v);
int bin_string_to_int (std::string s);

long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   auto g_rate = calc_g_rate(input);
   auto e_rate = calc_e_rate(input);
   auto i_g_rate = bin_string_to_int(g_rate);
   auto i_e_rate = bin_string_to_int(e_rate);

   return i_g_rate*i_e_rate;
}

long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   return 0;
}

std::vector<int>
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

std::string
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

std::string
calc_g_rate (std::vector<std::string> v)
{
   std::vector<int> count = sum_bits(v);

   std::string rate = press_to_binary(v.size(), count, '1', '0', '1');

   return rate;
}

std::string
calc_e_rate (std::vector<std::string> v)
{
   std::vector<int> count = sum_bits(v);

   std::string rate = press_to_binary(v.size(), count, '0', '1', '1');

   return rate;
}

int
bin_string_to_int (std::string s)
{
   int result = 0;
   for(int bit_value = 1, i=s.size()-1; i>=0; --i, bit_value *= 2)
      if (s[i] == '1')
         result += bit_value;

   return result;
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