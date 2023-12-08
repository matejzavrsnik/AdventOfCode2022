#pragma once

#include "everything_bagel.h"

namespace aoc23::d7
{

struct hand { string cards; ll bid; };

enum class type {
   five,
   four,
   full_house,
   three,
   two_pair,
   one_pair,
   high_card
};

inline type
get_type(string cards)
{
   map<char, int> tally;
   for(const auto& card : cards)
      add_to_tally(tally, card);

   mset<int> sames;
   for(const auto& [card, count] : tally)
      sames.insert(count);

   if (sames.contains(5))
      return type::five;

   if (sames.contains(4))
      return type::four;

   if (sames.contains(3) && sames.contains(2))
      return type::full_house;

   if (sames.contains(3) && !sames.contains(2))
      return type::three;

   if (sames.count(2) == 2)
      return type::two_pair;

   if (sames.count(2) == 1 && sames.count(1) == 3)
      return type::one_pair;

   if (sames.count(1) == 5)
      return type::high_card;

   // ... or die
   std::terminate();
}

inline ll
worth_by_type(string cards)
{
   switch(get_type(cards)) {
   case type::five: return 7;
   case type::four: return 6;
   case type::full_house: return 5;
   case type::three: return 4;
   case type::two_pair: return 3;
   case type::one_pair: return 2;
   case type::high_card: return 1;
   }
   return 0;
}

inline ll
worth_by_strength( char card)
{
   switch(card) {
   case 'A': return 13;
   case 'K': return 12;
   case 'Q': return 11;
   case 'J': return 10;
   case 'T': return 9;
   case '9': return 8;
   case '8': return 7;
   case '7': return 6;
   case '6': return 5;
   case '5': return 4;
   case '4': return 3;
   case '3': return 2;
   case '2': return 1;
   }
   return 0;
}

inline bool
lesser_hand(hand l, hand r)
{
   if(worth_by_type(l.cards) < worth_by_type(r.cards))
      return true;

   if(worth_by_type(l.cards) > worth_by_type(r.cards))
      return false;

   for(auto card : {0,1,2,3,4})
      if(worth_by_strength(l.cards[card]) < worth_by_strength(r.cards[card]))
         return true;
      else if(worth_by_strength(l.cards[card]) > worth_by_strength(r.cards[card]))
         return false;

   return false;
}

inline ll
p1 (vec<string> input)
{
   vec<hand> hands;
   for(auto line : input) {
      vec<string> card_bid = absl::StrSplit(line, " ");
      string cards = card_bid[0].data();
      hands.emplace_back(hand{
         .cards = card_bid[0].data(),
         .bid  = strv_to_ll(card_bid[1])
      });
   }

   absl::c_sort(hands, lesser_hand);

   ll sum_rank = 0, rank = 1;
   for(auto hand : hands)
      sum_rank += hand.bid * rank++;

   return sum_rank;
}

struct hand2 { string cards; opt<string> cards_noj; ll bid; };

inline ll
worth_by_strength2( char card)
{
   switch(card) {
   case 'A': return 13;
   case 'K': return 12;
   case 'Q': return 11;
   case 'T': return 10;
   case '9': return 9;
   case '8': return 8;
   case '7': return 7;
   case '6': return 6;
   case '5': return 5;
   case '4': return 4;
   case '3': return 3;
   case '2': return 2;
   case 'J': return 1;
   }
   return 0;
}

inline bool
lesser_hand2(hand2 l, hand2 r)
{
   auto l_plays = l.cards_noj.has_value() ? l.cards_noj.value() : l.cards;
   auto r_plays = r.cards_noj.has_value() ? r.cards_noj.value() : r.cards;

   if(worth_by_type(l_plays) < worth_by_type(r_plays))
      return true;

   if(worth_by_type(l_plays) > worth_by_type(r_plays))
      return false;

   for(auto card : {0,1,2,3,4})
      if(worth_by_strength2(l.cards[card]) < worth_by_strength2(r.cards[card]))
         return true;
      else if(worth_by_strength2(l.cards[card]) > worth_by_strength2(r.cards[card]))
         return false;

   return false;
}

inline opt<string> best_possible_cards_from(const string& cards)
{
   int count = absl::c_count(cards, 'J');

   if (count == 0) return nullopt;

   if (count == 5) return "AAAAA";

   map<char, int> tally;
   for(const auto& card : cards)
      if (card != 'J')
         add_to_tally(tally, card);

   auto sorted_by_freq = sort_map_by_value(tally, mzlib::option::descending::yes);

   char optimal_non_joker = sorted_by_freq[0].first; // by default, optimal joker is the most frequent card
   if(sorted_by_freq[0].second == 1) // however, if none of the cards appear more than once
   {
      auto sorted_by_strength = cards;
      absl::c_sort(sorted_by_strength, [](char l, char r){ return worth_by_strength2(l) > worth_by_strength2(r); });
      optimal_non_joker = sorted_by_strength[0]; // then joker optimal joker is the strongest
   }

   string cards_jreplaced = cards;
   absl::c_replace(cards_jreplaced, 'J', optimal_non_joker);

   return cards_jreplaced;
}

inline ll
p2 (vec<string> input)
{
   vec<hand2> hands;
   for(auto line : input) {
      vec<string> card_bid = absl::StrSplit(line, " ");
      string cards = card_bid[0].data();
      hand2 h{
         .cards = card_bid[0].data(),
         .cards_noj = best_possible_cards_from(card_bid[0].data()),
         .bid  = strv_to_ll(card_bid[1])
      };
      hands.emplace_back(h);
   }

   absl::c_sort(hands, lesser_hand2);

   ll sum_rank = 0, rank = 1;
   for(auto hand : hands)
      sum_rank += hand.bid * rank++;

   return sum_rank;
}

}
