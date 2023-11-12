#include "shortest_path_bfs.h"
#include "convert_to_grid.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>


TEST(reusables, single_source_shortest_path_bfs)
{
   auto grid = convert_to_grid<int>({
      "aabqponm",
      "abcryxxl",
      "accszzxk",
      "acctuvwj",
      "abdefghi"
   });
   mzlib::grid::cell start{0, 0};

   auto steps_to_get_there = single_source_shortest_path_bfs(
      grid, start, destination_at_most_one_larger
   );

   ASSERT_EQ(31, mzlib::grid::access(steps_to_get_there, {5,2}));
}