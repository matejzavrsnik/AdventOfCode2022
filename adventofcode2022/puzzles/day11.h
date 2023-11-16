#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"
#include "iterators/copy_modify.h"
#include <numeric>
#include <ranges>
#include <algorithm>
#include <deque>

using namespace std;

using Number = unsigned long long;

namespace adventofcode2022::day11
{

/*
 *                 METHOD DECLARATIONS
 */


struct operation {
   string operator_sym;
   string operand;
   Number operator() (Number old) const {
      Number ioperand = operand == "old" ? old : stoull(operand);
      if(operator_sym=="+") return old+ioperand;
      if(operator_sym=="-") return old-ioperand;
      if(operator_sym=="*") {
         Number n = old*ioperand;
         //if (ioperand>0 && n<old) cout << "Ooops!" << endl;
         return n;
      }
      if(operator_sym=="/") return old/ioperand;
      terminate();
   };
};


struct monkey {

   Number inspections = 0;
   deque<Number> items;
   operation op;
   Number divisible_by;
   size_t if_true;
   size_t if_false;

   string debug_name;
   string debug_operation;
   string debug_operations_all;

   Number inspect_next_item()
   {
      ++inspections;
      Number item = items.front();
      items.pop_front();
      return item;
   }
};

inline vector<monkey>
parse (vector<string> input)
{
   vector<vector<string_view>> split_input;
   mzlib::copy_modify(input, split_input, [](const auto& e){
      return mzlib::split(e, " ,:");
   });

   vector<monkey> monkeys;
   for(const auto& line : split_input)
   {
      /*
        Monkey 0:
        Starting items: 74, 73, 57, 77, 74
        Operation: new = old * 11
        Test: divisible by 19
          If true: throw to monkey 6
          If false: throw to monkey 7

      */
      if(line.size() == 0)
         continue; // empty line
      if(line[0]=="Monkey") {
         monkeys.push_back(monkey{}); // warning: implies monkey number from position in file!
         monkeys.back().debug_name = line[1];
      }
      if(line[0]=="Starting") {
         transform(line.begin()+2, line.end(),
            back_inserter(monkeys.back().items),
            [](auto& e){ return stoi(e.data()); });
      }
      if(line[0]=="Operation") {
         monkeys.back().op.operator_sym = line[4];
         monkeys.back().op.operand = line[5];
      }
      if(line[0]=="Test") {
         monkeys.back().divisible_by = stoi(line[3].data());
      }
      if(line[0]=="If") {
         if(line[1]=="true") {
            monkeys.back().if_true=stoi(line[5].data());
         }
         if(line[1]=="false") {
            monkeys.back().if_false=stoi(line[5].data());
         }
      }
   }
   return monkeys;
}

inline vector<monkey>
do_rounds (vector<monkey> monkeys, long rounds, bool divide=true)
{
   for(auto round : views::iota(0,rounds))
   {
      //cout << "round " << round << endl;
      for(auto& monkey : monkeys)
      {
         //cout << "  turn: monkey " << monkey.debug_name << " with items ";
         //print_container_template(monkey.items); cout << endl;
         while(!monkey.items.empty())
         {
            Number item = monkey.inspect_next_item();
            //cout << "    inspecting: " << item << endl;
            //cout << "      op: " << monkey.op.operand << monkey.op.operator_sym << endl;
            item = monkey.op(item);
            //cout << "      new: " << item << endl;
            if (divide) item /= 3;
            //cout << "      item: " << item << endl;
            Number remainder = item % monkey.divisible_by;
            //cout << "      divisible by: " << monkey.divisible_by << "?" << endl;
            if (remainder == 0)
            {
               //cout << "        yes: throw to " << monkey.if_true << endl;
               //cout << "          monkey " << monkey.if_true << " had: ";
               //print_container_template(monkeys[monkey.if_true].items); cout << endl;
               monkeys[monkey.if_true].items.push_back(item);
               //cout << "          now it has:   ";
               //print_container_template(monkeys[monkey.if_true].items); cout << endl;
            }
            else
            {
               //cout << "        no: throw to " << monkey.if_false << endl;
               //cout << "          monkey " << monkey.if_false << " had: ";
               //print_container_template(monkeys[monkey.if_false].items); cout << endl;
               monkeys[monkey.if_false].items.push_back(item);
               //cout << "          now it has:   ";
               //print_container_template(monkeys[monkey.if_false].items); cout << endl;
            }
         }
      }
   }
   return monkeys;
}

/*
 *                 FOR SUBMISSIONS
 */

inline Number
part1 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   vector<monkey> monkeys = parse(input);
   monkeys = do_rounds(monkeys, 20);

   sort(monkeys.begin(), monkeys.end(),
      [](auto a, auto b){
         return a.inspections > b.inspections;
      });

   Number monkey_business = monkeys[0].inspections * monkeys[1].inspections;
   // guesses: 70176, 1088
   return monkey_business;
}




inline Number
part2 (std::string input_file)
{
   auto input = mzlib::read_file_lines(input_file);

   /*
   TYPE converted;
   mzlib::copy_modify(input, converted, [](auto& e){
      return CONVERSION;
   });
    */

   return -1;
}

/*
 *                 METHOD DEFINITIONS
 */


/*
 *                 EXTRA
 */

namespace bonus
{

}

}
