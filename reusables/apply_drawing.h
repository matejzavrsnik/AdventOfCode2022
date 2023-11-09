//
// Created by matej on 09/11/23.
//

#ifndef RECREATIONAL_REUSABLES_GRABBAG_H_APPLY_DRAWING_H
#define RECREATIONAL_REUSABLES_GRABBAG_H_APPLY_DRAWING_H

#include "grabbag.h"
#include "move_to_next_pixel.h"
#include "drawing_operation.h"

inline bool apply_drawing(
   mnvt& canvas,
   const mnvt& drawing,
   const mc2d& coor,
   const drawing_operation operation = drawing_operation::add
)
{
   // todo: if drawing too big, draw what fits and ignore the rest. currently I crash instead.
   mc2d drawing_pixel{0,0};
   const mc2d drawing_size = mnv::size(drawing);
   do
   {
      auto canvas_pixel = drawing_pixel+coor;
      const auto pixel_value = mnv::access(drawing, drawing_pixel);
      if (operation == drawing_operation::add)
         mnv::access(canvas, canvas_pixel) += pixel_value;
      else if (operation == drawing_operation::subtract)
         mnv::access(canvas, canvas_pixel) -= pixel_value;
   }
   while(move_to_next_pixel(drawing_pixel, {0, 0}, drawing_size));

   return true;
}

#endif //RECREATIONAL_REUSABLES_GRABBAG_H_APPLY_DRAWING_H
