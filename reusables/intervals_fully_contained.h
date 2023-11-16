//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_INTERVALS_FULLY_CONTAINED_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_INTERVALS_FULLY_CONTAINED_H

#include "interval_inside_the_other.h"

inline
bool
intervals_fully_contained (
   std::pair<int, int> a,
   std::pair<int, int> b)
{
   return interval_inside_the_other(a, b)
      || interval_inside_the_other(b, a);
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_INTERVALS_FULLY_CONTAINED_H
