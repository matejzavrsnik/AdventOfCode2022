//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_BINARY_STRING_TO_INT_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_BINARY_STRING_TO_INT_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "tools/nested_vector.h"
#include "iterators/copy_modify.h"
#include "filesystem/read_write_file.h"
#include <deque>
#include <ranges>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <string/split.h>
#include <lang/concepts.h>
#include <laws/screen_rectangles.h>
#include <nature/screen_rectangle.h>
#include <nature/vector.h>
#include <abstract/direction.h>

int binary_string_to_int (std::string s);

inline int
binary_string_to_int (std::string s)
{
   int result = 0;
   for(int bit_value = 1, i=s.size()-1; i>=0; --i, bit_value *= 2)
      if (s[i] == '1')
         result += bit_value;

   return result;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_BINARY_STRING_TO_INT_H
