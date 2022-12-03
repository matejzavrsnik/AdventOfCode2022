#pragma once

#include <algorithm>

template<class Container>
Container sets_intersection_plural(Container intersection, Container container)
{
   Container new_intersection;
   std::set_intersection(
      container.begin(), container.end(),
      intersection.begin(), intersection.end(),
      std::back_inserter(new_intersection)
   );
   return new_intersection;
}

template<class Container, class... Containers>
Container sets_intersection_plural(Container intersection, Container container, Containers... additional)
{
   Container new_intersection;
   std::set_intersection(
      container.begin(), container.end(),
      intersection.begin(), intersection.end(),
      std::back_inserter(new_intersection)
   );
   return sets_intersection_plural(new_intersection, additional...);
}
