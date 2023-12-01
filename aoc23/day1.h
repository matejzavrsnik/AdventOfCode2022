#pragma once

#include "everything_bagel.h"

namespace aoc23::d1
{

inline
char get_first_digit(string line)
{
   for(auto c : line)
      if(isdigit(c))
         return c;
   throw mzlib::exception::not_found();
}

inline
char get_last_digit(string line)
{
   auto it = find_if(line.rbegin(), line.rend(), isdigit);
   if(it != line.rend())
      return *it;
   throw mzlib::exception::not_found();
}

map<string, char> digit_names()
{
   static map<string, char> digit_names = {
      {"zero", '0'},
      {"one", '1'},
      {"two", '2'},
      {"three", '3'},
      {"four", '4'},
      {"five", '5'},
      {"six", '6'},
      {"seven", '7'},
      {"eight", '8'},
      {"nine", '9'}};

   return digit_names;
}

inline
bool string_is_prefix_of_any(string s, map<string, char> m)
{
   return std::any_of(m.begin(), m.end(), [&s](auto el){ return el.first.starts_with(s); });
}

inline
vec<char> get_all_digits_str(
   string line,
   map<string, char> digit_names)
{
   vec<char> digits;

   for(int i=0; i<line.size(); ++i)
   {
      if (isdigit(line[i]))
         digits.push_back(line[i]);

      // else try parse
      string candidate;
      for (int j = i; j < line.size(); ++j)
      {
         candidate += line[j];
         if (digit_names.contains(candidate)) {
            char digit = digit_names[candidate];
            digits.push_back(digit);
         }
         if (!string_is_prefix_of_any(candidate, digit_names)) {
            break;
         }
      }
   }

   return digits;
}

inline ll
p1 (string input_file)
{
   const auto lines = read_file_lines(input_file);

   ll calibration_number = 0;
   for(auto line : lines)
   {
      auto first = get_first_digit(line);
      auto last = get_last_digit(line);

      string str_number;
      str_number += first;
      str_number += last;
      ll ll_number = stoll(str_number);

      calibration_number += ll_number;
   }

   return calibration_number;
}






inline ll
p2 (string input_file)
{
   const auto lines = read_file_lines(input_file);

   ll calibration_number = 0;
   for(auto line : lines)
   {
      auto digits = get_all_digits_str(line, digit_names());

      string str_number;
      str_number += digits[0];
      str_number += digits[digits.size() - 1];
      ll ll_number = stoll(str_number);

      calibration_number += ll_number;
   }


   // Attempt with replace. Done that. It is incorrect in general case.
   // Consider: "twone"

   return calibration_number;
}

}
