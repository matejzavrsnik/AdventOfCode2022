#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "abstract/direction.h"
#include "nature/vector.h"
#include "laws/screen_rectangles.h"

namespace adventofcode2022::day8
{

/*
 *                 METHOD DECLARATIONS
 */

std::vector<std::vector<int>>
vis_grid (const std::vector<std::vector<int>>& trees);

std::vector<std::vector<int>>
scenic_grid (const std::vector<std::vector<int>>& trees);

template<class VectorT>
VectorT move(VectorT c, const mzlib::direction d)
{
   switch (d)
   {
   case mzlib::direction::n: c += VectorT{-1,0}; break;
   case mzlib::direction::s: c += VectorT{1,0}; break;
   case mzlib::direction::e: c += VectorT{0,1}; break;
   case mzlib::direction::w: c += VectorT{0,-1}; break;

   case mzlib::direction::ne: c += VectorT{-1,1}; break;
   case mzlib::direction::nw: c += VectorT{-1,-1}; break;
   case mzlib::direction::se: c += VectorT{1,1}; break;
   case mzlib::direction::sw: c += VectorT{1,-1}; break;
   }
   return c;
}

/*
 *                 FOR SUBMISSIONS
 */

inline long
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<std::vector<int>> trees;
   for(const auto& in : input) {
      std::vector<int> tree_row;
      for(const auto& c : in)
         tree_row.push_back(c-'0');
      trees.push_back(tree_row);
   }

   std::vector<std::vector<int>> vis = vis_grid(trees);

   int count=0;
   for(const auto& row : vis)
      for(const auto& v : row)
         if (v>=1)
            ++count;

   return count;
}

inline long
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   std::vector<std::vector<int>> trees;
   for(const auto& in : input) {
      std::vector<int> tree_row;
      for(const auto& c : in)
         tree_row.push_back(c-'0');
      trees.push_back(tree_row);
   }

   std::vector<std::vector<int>> scenity = scenic_grid(trees);

   int max=0;
   for(const auto& r : scenity)
      for(const auto& s : r)
         if (s>max)
            max=s;

   return max;
}

/*
 *                 METHOD DEFINITIONS
 */

// not my proudest moment :)
inline std::vector<std::vector<int>>
vis_grid (const std::vector<std::vector<int>>& trees)
{
   auto vis = trees;
   for(auto& row : vis)
      for(auto& tree : row)
         tree = 0;

   const int rows = trees.size();
   const int cols = trees[0].size();
   int maxh;

   // left -> right
   for(int row=0; row<rows; ++row) // top->bottom
   {
      maxh = -1;
      for (int col = 0; col < cols; ++col) // left->right
         if (trees[row][col] > maxh)
         {
            maxh = trees[row][col];
            vis[row][col]++;
         }
   }

   // right -> left
   for(int row=0; row<rows; ++row) // top->bottom
   {
      maxh = -1;
      for (int col = cols - 1; col >= 0; --col) // right->left
         if (trees[row][col] > maxh)
         {
            maxh = trees[row][col];
            vis[row][col]++;
         }
   }

   // top->bottom
   for(int col=0; col<cols; ++col) // left->right
   {
      maxh = -1;
      for (int row = 0; row < rows; ++row) // top->bottom
         if (trees[row][col] > maxh)
         {
            maxh = trees[row][col];
            vis[row][col]++;
         }
   }

   // bottom->top
   for(int col=0; col<cols; ++col) // left->right
   {
      maxh = -1;
      for (int row = rows - 1; row >= 0; --row) // bottom->top
         if (trees[row][col] > maxh)
         {
            maxh = trees[row][col];
            vis[row][col]++;
         }
   }

   return vis;
}

inline int
visibility (
   mzlib::coordinates2d house,
   const std::vector<std::vector<int>>& trees,
   mzlib::direction d
)
{
   mzlib::screen_rectangle<mzlib::coordinates2d> forest{{0,0},{(int)trees.size()-1, (int)trees[0].size()-1}};
   mzlib::law::screen_rectangles<mzlib::coordinates2d> area;
   area.consider(forest);
   const int house_h = trees[house[0]][house[1]];

   int visibility = 0;

   mzlib::coordinates2d tree = house;
   while(tree = move(tree, d), area.is_in_inclusive(tree))
   {
      visibility++;
      int tree_h = trees[tree[0]][tree[1]];
      if (tree_h >= house_h)
         break;
   }

   return visibility;
}

inline std::vector<std::vector<int>>
scenic_grid (const std::vector<std::vector<int>>& trees)
{
   auto scenity = trees;
   for (auto& row: scenity)
      for (auto& s: row)
         s = 0;

   const int rows = trees.size();
   const int cols = trees[0].size();

   // for each tree house
   mzlib::coordinates2d house;
   for(house[0]=0; house[0]<rows; ++house[0])
      for(house[1]=0; house[1]<cols; ++house[1])
      {
         int vis_n = visibility(house, trees, mzlib::direction::n);
         int vis_s = visibility(house, trees, mzlib::direction::s);
         int vis_e = visibility(house, trees, mzlib::direction::e);
         int vis_w = visibility(house, trees, mzlib::direction::w);
         scenity[house[0]][house[1]] = vis_n * vis_s * vis_e * vis_w;
      }

   return scenity;
}

/*
 *                 EXTRA
 */

namespace bonus
{

}

}
