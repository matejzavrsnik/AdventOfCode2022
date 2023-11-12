#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include "tools/grid.h"
#include "iterators/circular_next.h"
#include "../../reusables/grabbag.h"
#include "../../reusables/move_screen.h"
#include "../../reusables/move_if_not_blocked.h"
#include "../../reusables/apply_drawing.h"

using namespace std;

namespace adventofcode2022::day17
{

/*
 *                 METHODS
 */



const mzlib::grid::type<int> rock_m = {
   {1,1,1,1}
};
const mzlib::grid::type<int> rock_p = {
   {0,1,0},
   {1,1,1},
   {0,1,0},
};
const mzlib::grid::type<int> rock_l = {
   {0,0,1},
   {0,0,1},
   {1,1,1},
};
const mzlib::grid::type<int> rock_i = {
   {1},
   {1},
   {1},
   {1},
};
const mzlib::grid::type<int> rock_d = {
   {1,1},
   {1,1},
};

const vector rocks = {
   rock_m,
   rock_p,
   rock_l,
   rock_i,
   rock_d
};






inline mzlib::grid::cell coordinates_after_push(
   char jet,
   const mzlib::grid::type<int>& chamber,
   const mzlib::grid::type<int>& rock,
   const mzlib::grid::cell& coor)
{
   mzlib::grid::cell new_coor = coor;
   switch(jet)
   {
   case '>':
      new_coor = move_screen(coor, mzlib::direction::e);
      break;
   case '<':
      new_coor = move_screen(coor, mzlib::direction::w);
      break;
   }
   return new_coor;
}




inline int get_highest_rock(const mzlib::grid::type<int>& chamber)
{
   for (int row = 0; row < chamber.size(); row++)
      for (int col = 0; col < chamber[0].size(); col++)
         if (chamber[row][col] > 0)
            return chamber.size() - row;
   return chamber.size();
}



/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   auto chamber = mzlib::grid::construct(1, 7, 0);
   auto jet_it = input[0].begin();

   auto rock_it = rocks.begin();
   int highest_rock=0;
   for(auto rock_count : std::views::iota(0, 2022))
   {
      // increase chamber to accomodate rock
      auto needed_height = highest_rock+1+3+mzlib::grid::height(*rock_it);
      if(needed_height > mzlib::grid::height(chamber))
      {
         mzlib::grid::add_top(chamber, needed_height-mzlib::grid::height(chamber)-1, 0);
      }

      mzlib::grid::cell rock_coor{2, static_cast<long>(mzlib::grid::height(chamber)-highest_rock-3-mzlib::grid::height(*rock_it))};
      bool rock_fell = true;

      apply_drawing(chamber, *rock_it, rock_coor);

      while(rock_fell)
      {
         // jet push
         auto pushed_coor = coordinates_after_push(*jet_it, chamber, *rock_it, rock_coor);
         rock_coor = move_if_not_blocked(chamber, *rock_it, rock_coor, pushed_coor);

         // fall
         auto fallen_coor = move_screen(rock_coor, mzlib::direction::s);
         rock_coor = move_if_not_blocked(chamber, *rock_it, rock_coor, fallen_coor);
         rock_fell = rock_coor == fallen_coor;

         mzlib::circular_next_iterator(jet_it, input[0].begin(), input[0].end());
      }

      highest_rock = get_highest_rock(chamber);
      mzlib::circular_next_iterator(rock_it, rocks.begin(), rocks.end());
   }

   // 3233 too high, 3442 too high, 3212 not correct, 2958 is not correct
   return highest_rock;
}


// when a collection of elements starts repeating:
// example:
// a,k,d,h,f,r,n,n,s,m,d,l,v,n,g,f,k,s,n,s,c,n,h,g,d,k,s,w,r,h,g,b,c,x,i,3,d,n,h,g,d,k,s,w,r,h,g,b,c,x,i,3,d
// | start of the collection                 |starts repeating here          |this is repeated part
template<typename Container, typename Iterator>
std::optional<std::pair<Iterator, Iterator>> did_it_start_repeating(Container& container)
{
   using ReverseIterator = decltype(container.rbegin());
   std::set<ReverseIterator> candidates;
/*
   auto size = container.size()/2;
   for(auto compare_with = std::advance(container.rbegin(), size))
   auto final_element = container.rbegin();
*/

   return std::nullopt;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   auto chamber = mzlib::grid::construct(1, 7, 0);
   auto jet_it = input[0].begin();

   auto rock_it = rocks.begin();
   int highest_rock=0;
   vector<int> highest_rocks{0};
   vector<int> highest_rocks_diff{0};
   for(auto rock_count : std::views::iota(0, 10'000))
   {
      //cout << endl << "Rock: " << rock_count+1 << "th" << endl;
      //print_field(*rock_it, {{0, "."},{1, "#"}}, 1);

      // increase chamber to accomodate rock
      auto needed_height = highest_rock+1+3+mzlib::grid::height(*rock_it);
      if(needed_height > mzlib::grid::height(chamber))
      {
         mzlib::grid::add_top(chamber, needed_height-mzlib::grid::height(chamber)-1, 0);
      }

      mzlib::grid::cell rock_coor{2, static_cast<long>(mzlib::grid::height(chamber)-highest_rock-3-mzlib::grid::height(*rock_it))};
      bool rock_fell = true;

      apply_drawing(chamber, *rock_it, rock_coor);
      //cout << endl;
      //print_field(chamber, {{0, "."},{1, "#"}}, 1);

      while(rock_fell)
      {
         // jet push
         //cout << endl << "Jet: " << *jet_it << " (" << std::distance(input[0].begin(), jet_it)+1 << "th jet in pattern " << input[0] << ")";
         auto pushed_coor = coordinates_after_push(*jet_it, chamber, *rock_it, rock_coor);
         rock_coor = move_if_not_blocked(chamber, *rock_it, rock_coor, pushed_coor);

         //cout << endl;
         //print_field(chamber, {{0, "."},{1, "#"}}, 1);

         // fall
         auto fallen_coor = move_screen(rock_coor, mzlib::direction::s);
         rock_coor = move_if_not_blocked(chamber, *rock_it, rock_coor, fallen_coor);
         rock_fell = rock_coor == fallen_coor;

         //cout << endl << "Fall" << endl;
         //print_field(chamber, {{0, "."},{1, "#"}}, 1);

         //if(rock_fell)
         mzlib::circular_next_iterator(jet_it, input[0].begin(), input[0].end());
      }

      highest_rock = get_highest_rock(chamber);
      highest_rocks_diff.push_back(highest_rock-highest_rocks.back());
      highest_rocks.push_back(highest_rock);
      mzlib::circular_next_iterator(rock_it, rocks.begin(), rocks.end());
   }

   print(highest_rocks_diff);

   // 3233 too high, 3442 too high, 3212 not correct, 2958 is not correct
   return highest_rock;
}

}