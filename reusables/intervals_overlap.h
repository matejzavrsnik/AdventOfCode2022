//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_INTERVALS_OVERLAP_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_INTERVALS_OVERLAP_H

#include "grabbag.h"
#include "interval_overlaps_the_other.h"

inline bool
intervals_overlap (
   std::pair<int, int> a,
   std::pair<int, int> b)
{
   return interval_overlaps_the_other(a, b)
      || interval_overlaps_the_other(b, a);
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_INTERVALS_OVERLAP_H
