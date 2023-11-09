//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_GET_ALL_CELLS_WITH_VALUE_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_GET_ALL_CELLS_WITH_VALUE_H

#include "move_screen.h"
#include "iterators/circular_next.h"
#include "tools/nested_vector.h"
#include "iterators/copy_modify.h"
#include "filesystem/read_write_file.h"
#include "grabbag.h"
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

inline std::vector<cell> get_all_cells_with_value(const std::vector<std::vector<int>>& field, int value)
{
   std::vector<cell> all_of_value;
   for(int row = 0; row < field.size(); ++row)
      for(int col = 0; col < field[0].size(); ++col)
         if(field[row][col] == value)
            all_of_value.push_back(cell{row,col});
   //cout << all_of_value.size() << endl;
   return all_of_value;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_GET_ALL_CELLS_WITH_VALUE_H
