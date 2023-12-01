#pragma once

#include "everything_bagel.h"

namespace aoc23::d1
{

inline char
get_first_digit(string line)
{
   auto first_digit = line
      | std::views::filter(isdigit)
      | std::views::take(1);

   return first_digit.front();
}

inline char
get_last_digit(string line)
{
   auto first_digit = line
      | std::views::reverse
      | std::views::filter(isdigit)
      | std::views::take(1);

   return first_digit.front();
}

inline map<string, string>
name_to_digit()
{
   static map<string, string> digit_names = {
      {"zero", "0"},
      {"one", "1"},
      {"two", "2"},
      {"three", "3"},
      {"four", "4"},
      {"five", "5"},
      {"six", "6"},
      {"seven", "7"},
      {"eight", "8"},
      {"nine", "9"}};

   return digit_names;
}

inline bool
any_key_starts_with(map<string, string> m, string s)
{
   auto such_keys = m
      | std::views::keys
      | std::views::filter([&s](string digit_name){ return digit_name.starts_with(s); });

   return !such_keys.empty();
}

inline vec<string>
get_all_digits_str(
   string line,
   map<string, string> name_to_digit)
{
   vec<string> digits;

   for(int i=0; i<line.size(); ++i)
   {
      if (isdigit(line[i]))
         digits.push_back(ctos(line[i]));

      // else try parse
      string name_candidate;
      for (int j = i; j < line.size(); ++j)
      {
         name_candidate += line[j];
         if (name_to_digit.contains(name_candidate))
         {
            digits.push_back(name_to_digit[name_candidate]);
            continue;
         }
         if (!any_key_starts_with(name_to_digit, name_candidate))
         {
            break;
         }
      }
   }

   return digits;
}

inline ll
p1 (vec<string> input)
{
   ll calibration_number = 0;
   for(auto line : input)
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
p2 (vec<string> input)
{
   ll calibration_number = 0;
   for(auto line : input)
   {
      auto digits = get_all_digits_str(line, name_to_digit());

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
