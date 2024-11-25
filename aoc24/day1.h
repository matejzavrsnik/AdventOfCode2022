#pragma once

#include "everything_bagel.h"

namespace aoc24::d1
{

inline vec<string>
get_all_digits_str(
   const string& line,
   const map<string, string>& name_to_digit)
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
            digits.push_back(name_to_digit.at(name_candidate));
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
   for(const auto& line : input)
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
