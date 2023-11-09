#include <gtest/gtest.h>

#include "../puzzles/day6.h"
#include "../puzzles/day8.h"
#include "../puzzles/day9.h"
#include "../puzzles/day10.h"
#include "../puzzles/day11.h"
#include "../puzzles/day17.h"

using namespace adventofcode2022;

TEST(adventofcode2022_methods, day6_is_marker)
{
   ASSERT_TRUE(day6::bonus::is_marker({'a','b','c','d'}));
   ASSERT_FALSE(day6::bonus::is_marker({'a','b','c','c'}));
}

TEST(adventofcode2022_methods, day8_visibility)
{
   ASSERT_EQ(1, day8::visibility({0,0}, {{6,6,3,1}}, mzlib::direction::e));
   ASSERT_EQ(3, day8::visibility({0,0}, {{6,5,5,5}}, mzlib::direction::e));
   ASSERT_EQ(2, day8::visibility({0,0}, {{6,3,6,4}}, mzlib::direction::e));
   ASSERT_EQ(6, day8::visibility({0,0}, {{6,3,2,0,4,4,6}}, mzlib::direction::e));

}

TEST(adventofcode2022_methods, day9_sample_input)
{
   std::vector<std::pair<char, int>> directions ={
      {'R', 4},
      {'U', 4},
      {'L', 3},
      {'D', 1},
      {'R', 4},
      {'D', 1},
      {'L', 5},
      {'R', 2}
   };
   auto v = day9::get_visited(directions, 2);

   ASSERT_EQ(13, v.size());
}


TEST(adventofcode2022_methods, day9_sample_input_2)
{
   std::vector<std::pair<char, int>> directions ={
      {'R', 5},
      {'U', 8},
      {'L', 8},
      {'D', 3},
      {'R', 17},
      {'D', 10},
      {'L', 25},
      {'U', 20}
   };
   auto v = day9::get_visited(directions, 10);

   ASSERT_EQ(36, v.size());
}

TEST(adventofcode2022_methods, day10_next_significant_tick)
{
   ASSERT_EQ(20, day10::next_significant_tick(0));
   ASSERT_EQ(60, day10::next_significant_tick(20));
   ASSERT_EQ(100, day10::next_significant_tick(60));
   ASSERT_EQ(140, day10::next_significant_tick(100));
   ASSERT_EQ(180, day10::next_significant_tick(140));
   ASSERT_EQ(220, day10::next_significant_tick(180));
}

TEST(adventofcode2022_methods, day11_operation)
{
   ASSERT_EQ(50,  (day11::operation{.operator_sym="+", .operand="20"}(30)));
   ASSERT_EQ(40,  (day11::operation{.operator_sym="+", .operand="10"}(30)));
   ASSERT_EQ(10,  (day11::operation{.operator_sym="-", .operand="20"}(30)));
   ASSERT_EQ(20,  (day11::operation{.operator_sym="-", .operand="10"}(30)));
   ASSERT_EQ(600, (day11::operation{.operator_sym="*", .operand="20"}(30)));
   ASSERT_EQ(300, (day11::operation{.operator_sym="*", .operand="10"}(30)));
   ASSERT_EQ(1,   (day11::operation{.operator_sym="/", .operand="20"}(30)));
   ASSERT_EQ(3,   (day11::operation{.operator_sym="/", .operand="10"}(30)));
}

TEST(adventofcode2022_methods, day11_sample_input_part1)
{
   vector<string> input
   {
      "Monkey 0:",
      "  Starting items: 79, 98",
      "  Operation: new = old * 19",
      "  Test: divisible by 23",
      "    If true: throw to monkey 2",
      "    If false: throw to monkey 3",
      "",
      "Monkey 1:",
      "  Starting items: 54, 65, 75, 74",
      "  Operation: new = old + 6",
      "  Test: divisible by 19",
      "    If true: throw to monkey 2",
      "    If false: throw to monkey 0",
      "",
      "Monkey 2:",
      "  Starting items: 79, 60, 97",
      "  Operation: new = old * old",
      "  Test: divisible by 13",
      "    If true: throw to monkey 1",
      "    If false: throw to monkey 3",
      "",
      "Monkey 3:",
      "  Starting items: 74",
      "  Operation: new = old + 3",
      "  Test: divisible by 17",
      "    If true: throw to monkey 0",
      "    If false: throw to monkey 1"
   };

   vector<day11::monkey> monkeys = day11::parse(input);
   monkeys = day11::do_rounds(monkeys, 20);

   sort(monkeys.begin(), monkeys.end(),
      [](auto a, auto b){
         return a.inspections > b.inspections;
      });

   int monkey_business = monkeys[0].inspections * monkeys[1].inspections;

   ASSERT_EQ(10605, monkey_business);
}

TEST(adventofcode2022_methods, DISABLED_day11_sample_input_part2)
{
   vector<string> input
      {
         "Monkey 0:",
         "  Starting items: 79, 98",
         "  Operation: new = old * 19",
         "  Test: divisible by 23",
         "    If true: throw to monkey 2",
         "    If false: throw to monkey 3",
         "",
         "Monkey 1:",
         "  Starting items: 54, 65, 75, 74",
         "  Operation: new = old + 6",
         "  Test: divisible by 19",
         "    If true: throw to monkey 2",
         "    If false: throw to monkey 0",
         "",
         "Monkey 2:",
         "  Starting items: 79, 60, 97",
         "  Operation: new = old * old",
         "  Test: divisible by 13",
         "    If true: throw to monkey 1",
         "    If false: throw to monkey 3",
         "",
         "Monkey 3:",
         "  Starting items: 74",
         "  Operation: new = old + 3",
         "  Test: divisible by 17",
         "    If true: throw to monkey 0",
         "    If false: throw to monkey 1"
      };

   vector<day11::monkey> monkeys = day11::parse(input);
   monkeys = day11::do_rounds(monkeys, 10000, false);

   sort(monkeys.begin(), monkeys.end(),
      [](auto a, auto b){
         return a.inspections > b.inspections;
      });

   int monkey_business = monkeys[0].inspections * monkeys[1].inspections;

   ASSERT_EQ(2713310158, monkey_business);
}





/*
 *       TEMPLATE
 */

/*
TEST(adventofcode2022_methods, dayX_method_name)
{
   ASSERT_EQ(VALUE, dayX::method_name());
}
*/
