#pragma once

#include "filesystem/read_write_file.h"
#include "string/split.h"

#include <string>
#include <map>
#include <numeric>

namespace adventofcode2022::day2
{

// A, X - rock (1)
// B, Y - paper (2)
// C, Z - scissors (3)
inline long
part1 (std::string input_file)
{
   auto strategy_guide = mzlib::read_file_lines(input_file);

   std::map<std::string_view, std::string_view> translate_my_shape{{"X", "A"}, // rock
      {"Y", "B"}, // paper
      {"Z", "C"}}; // scissors

   std::map<std::string_view, int> choice_score{{"X", 1}, // rock 1 point
      {"Y", 2}, // paper 2 points
      {"Z", 3}}; // scissors 3 points

   std::map<std::string_view, std::string_view> defeats{{"X", "C"}, // rock defeats scissors
      {"Y", "A"}, // paper defeats rock
      {"Z", "B"}, // scissors defeat paper
   };

   long cumulative_score = 0;
   const short their = 0, my = 1;

   for (auto game: strategy_guide)
   {
      auto sides_played = mzlib::split(game, " ");

      cumulative_score += choice_score[sides_played[my]];

      if (defeats[sides_played[my]] == sides_played[their])
         cumulative_score += 6; // I win, 6 points
      else if (translate_my_shape[sides_played[my]] == sides_played[their])
         cumulative_score += 3; // draw, 3 points
      // else nothing
   }

   return cumulative_score;
}

// A, rock (1)      X - lose
// B, paper (2)     Y - draw
// C, scissors (3)  Z - win
inline long
part2 (std::string input_file)
{
   auto strategy_guide = mzlib::read_file_lines(input_file);

   std::string_view lose = "X", draw = "Y", win = "Z";
   std::string_view rock = "A", paper = "B", scissors = "C";

   std::map<std::string_view, int> choice_score{{rock, 1}, // rock 1 point
      {paper, 2}, // paper 2 points
      {scissors, 3}}; // scissors 3 points

   // If they play ___ and I need to ___ I will play ___
   std::map<std::string_view, std::map<std::string_view, std::string_view>>
      hand_suggestion{{rock, {{lose, scissors}, // if they play rock and I need to lose, I play scissors
      {win, paper}}},    // if they play rock and I need to win, I play paper
      {paper, {{lose, rock}, {win, scissors}}}, {scissors, {{lose, paper}, {win, rock}}}};

   long cumulative_score = 0;
   const short their_hand = 0, outcome = 1;

   for (auto game: strategy_guide)
   {
      auto row = mzlib::split(game, " ");

      // score the outcome
      if (row[outcome] == draw)
         cumulative_score += 3;
      if (row[outcome] == win)
         cumulative_score += 6;

      // score my hand
      auto my_hand = row[outcome] == draw ? row[their_hand] : hand_suggestion[row[their_hand]][row[outcome]];

      cumulative_score += choice_score[my_hand];
   }

   return cumulative_score;
}

namespace bonus
{

// trying to make this a one-liner at the expense of everything else. For the bonus.
inline long
part2 (std::string input_file)
{
   auto strategy_guide = mzlib::read_file_lines(input_file);

   return std::accumulate(
      strategy_guide.begin(), strategy_guide.end(), 0, [] (
         auto score,
         auto& game
      )
      {
         const auto& r = mzlib::split(game, " ");
         const auto& t = r[0][0] - 'A' + 1;
         const auto& o = r[1][0];

         return score += o == 'Z' ? (6 + (t == 0 ? 3 : t == 3 ? 1 : t + 1)) : o == 'Y' ? (3 + (t)) : o == 'X' ? (
            0 + (t == 1 ? 3 : t == 5 ? 1 : t - 1)) : 0;
      }
   );
}

// A version that uses emojis instead of letters :)
// I can afford to do that because my original code didn't imply relationships between symbols.
inline long
part2v2 (std::string input_file)
{
   auto strategy_guide = mzlib::read_file_lines(input_file);

   std::map<std::string_view, std::string_view> translate{{"A", "🪨"}, // rock
      {"B", "📜"}, // paper
      {"C", "✂️"}, // scissors
      {"X", "☠️"}, // lose
      {"Y", "🎨"}, // draw
      {"Z", "🏆"}, // win
   };

   std::map<std::string_view, int> choice_score{{"🪨", 1}, {"📜", 2}, {"✂️", 3}};

   // If they play ___ and I need to ___ I will play ___
   std::map<std::string_view, std::map<std::string_view, std::string_view>> hand_suggestion
      {{"🪨", {{"☠️", "✂️"}, {"🏆", "📜"}}}, {"📜", {{"☠️", "🪨"}, {"🏆", "✂️"}}}, {"✂️", {{"☠️", "📜"}, {"🏆", "🪨"}}}};

   // 🤣

   long cumulative_score = 0;

   for (auto game: strategy_guide)
   {
      auto row = mzlib::split(game, " ");
      auto outcome = translate[row[1]];
      auto their_hand = translate[row[0]];

      // score the outcome
      if (outcome == "🎨")
         cumulative_score += 3 + choice_score[their_hand];
      if (outcome == "🏆")
         cumulative_score += 6 + choice_score[hand_suggestion[their_hand]["🏆"]];
      if (outcome == "☠️")
         cumulative_score += 0 + choice_score[hand_suggestion[their_hand]["☠️"]];
   }

   return cumulative_score;
}

}

}