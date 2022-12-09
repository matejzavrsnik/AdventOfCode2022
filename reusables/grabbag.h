#pragma once

#include <abstract/direction.h>

#include <lang/concepts.h>
#include <algorithm>
#include <iterator>
#include "nature/vector.h"

template<class VectorT>
VectorT move_cartesian(VectorT c, const mzlib::direction d)
{
   switch (d)
   {
   case mzlib::direction::n: c += VectorT{0,1}; break;
   case mzlib::direction::s: c += VectorT{0,-1}; break;
   case mzlib::direction::e: c += VectorT{1,0}; break;
   case mzlib::direction::w: c += VectorT{-1,0}; break;

   case mzlib::direction::ne: c += VectorT{1,1}; break;
   case mzlib::direction::nw: c += VectorT{-1,1}; break;
   case mzlib::direction::se: c += VectorT{1,-1}; break;
   case mzlib::direction::sw: c += VectorT{-1,-1}; break;
   case mzlib::direction::centre: break;
   }
   return c;
}

template<class VectorT>
inline mzlib::direction get_direction_cartesian(VectorT from, VectorT to)
{
   auto dir_v = to-from;

   if(dir_v[0] == 0 && dir_v[1] > 0) return mzlib::direction::n;
   if(dir_v[0] == 0 && dir_v[1] < 0) return mzlib::direction::s;
   if(dir_v[0] > 0 && dir_v[1] == 0) return mzlib::direction::e;
   if(dir_v[0] < 0 && dir_v[1] == 0) return mzlib::direction::w;

   if(dir_v[0] > 0 && dir_v[1] > 0) return mzlib::direction::ne;
   if(dir_v[0] < 0 && dir_v[1] > 0) return mzlib::direction::nw;
   if(dir_v[0] > 0 && dir_v[1] < 0) return mzlib::direction::se;
   if(dir_v[0] < 0 && dir_v[1] < 0) return mzlib::direction::sw;

   return mzlib::direction::centre;
}

inline bool are_touching(mzlib::coordinates2d a, mzlib::coordinates2d b)
{
   auto diff = a - b;
   return abs(diff[0]) <= 1 && abs(diff[1]) <= 1;
}
