//
// Copyright (c) 2023 Matej Zavrsnik
//
// Web:  matejzavrsnik.com
// Mail: matejzavrsnik@gmail.com
//

#pragma once

#include "interval_inside_the_other.h"

template<typename T>
bool
intervals_fully_contained (
   const std::pair<T, T>& a,
   const std::pair<T, T>& b)
{
   return interval_inside_the_other(a, b)
      || interval_inside_the_other(b, a);
}


