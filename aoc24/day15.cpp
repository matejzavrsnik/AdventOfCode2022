#include <gtest/gtest.h>

#include "day15.h"

using namespace aoc24;

TEST(aoc24, d15_ok_to_move)
{
   auto g = grid::convert_to_grid<char>({
      "##########",
      "#OOO@....#",
      "##########",
   });

   ASSERT_FALSE(d15::ok_to_move(g, {4,1}, direction::w));
}

TEST(aoc24, d15_p1_smaller_example)
{
   vec<string> input = {
      "########",
      "#..O.O.#",
      "##@.O..#",
      "#...O..#",
      "#.#.O..#",
      "#...O..#",
      "#......#",
      "########",
      "",
      "<^^>>>vv<v>>v<<"
   };
   auto result = d15::p1(input);
   ASSERT_EQ(2028, result);
}

TEST(aoc24, d15_p1_example)
{
   vec<string> input = {
      "##########",
      "#..O..O.O#",
      "#......O.#",
      "#.OO..O.O#",
      "#..O@..O.#",
      "#O#..O...#",
      "#O..O..O.#",
      "#.OO.O.OO#",
      "#....O...#",
      "##########",
      "",
      "<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^",
      "vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v",
      "><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<",
      "<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^",
      "^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><",
      "^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^",
      ">^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^",
      "<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>",
      "^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>",
      "v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^"
   };
   auto result = d15::p1(input);
   ASSERT_EQ(10092, result);
}

TEST(aoc24, d15_p1)
{
   vec<string> input = read_file_lines("./res/aoc24/day15.input.txt");
   auto result = d15::p1(input);
   ASSERT_EQ(1429911, result);
}

TEST(aoc24, d15_ok_to_move_dbl_e_w)
{
   auto g = grid::convert_to_grid<char>({
      "##########",
      "##[]@...##",
      "##########",
   });
   auto robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::w));

   g = grid::convert_to_grid<char>({
      "##########",
      "##.[]@..##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::w));

   g = grid::convert_to_grid<char>({
      "##########",
      "##...@[]##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::e));

   g = grid::convert_to_grid<char>({
      "##########",
      "##..@[].##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::e));

   g = grid::convert_to_grid<char>({
      "##########",
      "##[][]@.##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::w));

   g = grid::convert_to_grid<char>({
      "##########",
      "##.[][]@##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::w));

   g = grid::convert_to_grid<char>({
      "##########",
      "##.@[][]##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::e));

   g = grid::convert_to_grid<char>({
      "##########",
      "##@[][].##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::e));

   g = grid::convert_to_grid<char>({
      "##############",
      "##@[][][].[]##",
      "##############",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::e));
}

TEST(aoc24, d15_ok_to_move_dbl_n_s)
{
   auto g = grid::convert_to_grid<char>({
      "##########",
      "##......##",
      "##......##",
      "##..[]..##",
      "##..@...##",
      "##########",
   });
   auto robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##......##",
      "##......##",
      "##..[]..##",
      "##...@..##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##......##",
      "##..[]..##",
      "##..[]..##",
      "##...@..##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##......##",
      "##..[]..##",
      "##..[]..##",
      "##..@...##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##......##",
      "##.[][].##",
      "##..[]..##",
      "##..@...##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##......##",
      "##.[][].##",
      "##..[]..##",
      "##...@..##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_TRUE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##..[]..##",
      "##..@...##",
      "##......##",
      "##......##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##..[]..##",
      "##...@..##",
      "##......##",
      "##......##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##.[]...##",
      "##..[]..##",
      "##...@..##",
      "##......##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::n));

   g = grid::convert_to_grid<char>({
      "##########",
      "##....#.##",
      "##.[][].##",
      "##..[]..##",
      "##...@..##",
      "##########",
   });
   robot = grid::get_all_cells_with_value(g, '@')[0];
   ASSERT_FALSE(d15::ok_to_move_dbl(g, robot, direction::n));
}

TEST(aoc24, d15_p2_smaller_example)
{
   vec<string> input = {
      "#######",
      "#...#.#",
      "#.....#",
      "#..OO@#",
      "#..O..#",
      "#.....#",
      "#######",
      "",
      "<vv<<^^<<^^"
   };
   auto result = d15::p2(input);
   ASSERT_EQ(618, result);
}

TEST(aoc24, d15_move_dbl_npc) {
   auto g = grid::convert_to_grid<char>({
      "####################",
      "##[]..[]....[]..[]##",
      "##[]..........[]..##",
      "##......@[][][].[]##",
      "##....[]..[]..[]..##",
      "##..##....[]......##",
      "##...[].......[]..##",
      "##.....[]..[].[][]##",
      "##........[]......##",
      "####################"
   });
   auto robot = grid::get_all_cells_with_value(g, '@')[0];
   auto result = d15::move_dbl_npc(g, robot, direction::e);
   //print(g);
   ASSERT_TRUE(true);
}

TEST(aoc24, d15_p2_example)
{
   vec<string> input = {
      "##########",
      "#..O..O.O#",
      "#......O.#",
      "#.OO..O.O#",
      "#..O@..O.#",
      "#O#..O...#",
      "#O..O..O.#",
      "#.OO.O.OO#",
      "#....O...#",
      "##########",
      "",
      "<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^",
      "vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v",
      "><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<",
      "<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^",
      "^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><",
      "^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^",
      ">^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^",
      "<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>",
      "^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>",
      "v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^"
   };
   auto result = d15::p2(input);
   ASSERT_EQ(9021, result);
}

TEST(aoc24, dX_p2)
{
   vec<string> input = read_file_lines("./res/aoc24/day15.input.txt");
   auto result = d15::p2(input);
   ASSERT_EQ(1453087, result);
}