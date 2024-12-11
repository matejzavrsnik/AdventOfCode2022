#pragma once

#include "everything_bagel.h"

namespace aoc24::d9
{

ll idx_to_id(ll index) {
   return index >= 0 ? index / 2 : index;
}

ll next_left(const string& diskmap) {
   static bool file = false;
   static ll diskmap_index=0;
   static ll count=0;
   if(count==0 && diskmap_index<diskmap.size()) {
      auto ch = diskmap[diskmap_index++];
      count=ctoll(ch);
      file=!file;
   }
   if(count==0 && diskmap_index<diskmap.size()) {
      auto ch = diskmap[diskmap_index++];
      count=ctoll(ch);
      file=!file;
   }
   --count;
   return file ? diskmap_index : -1;
}

ll next_right(const string& diskmap) {
   static bool file = diskmap.size()%2==0;
   static ll diskmap_index=diskmap.size();
   static ll count=0;
   if(count==0 && diskmap_index>0) {
      auto ch = diskmap[--diskmap_index];
      count=ctoll(ch);
      file=!file;
   }
   if(count==0 && diskmap_index>0) {
      auto ch = diskmap[--diskmap_index];
      count=ctoll(ch);
      file=!file;
   }
   --count;
   return file ? diskmap_index : -1;
}

ll calculate_checksum(string diskmap) {
   auto total_blocks = std::ranges::fold_left(
      diskmap | std::views::stride(2) | std::views::transform(ctoll),
      0, std::plus());

   ll cs=0, blocknumber=0;
   while (blocknumber<total_blocks) {
      ll diskmap_index = next_left(diskmap);
      while (diskmap_index<0)
         diskmap_index = next_right(diskmap);
      ll fileid = idx_to_id(diskmap_index);
      cs+=blocknumber*fileid;
      ++blocknumber;
   }
   return cs;
}

inline ll
p1 (vec<string> input)
{
   return calculate_checksum(input[0]);
}

struct file { ll fileid; ll blocks; ll freeafter; };
inline
std::ostream&
operator<< (
   std::ostream& os,
   file f)
{
   os << f.fileid << " " << f.blocks << " " << f.freeafter << endl;
   return os;
}

inline ll
p2 (vec<string> input)
{
   string diskmap = input[0];

   // parse
   vec<file> files =
      std::views::zip_transform(
         [](auto fileid, auto filer) {
            return file{
               .fileid = fileid,
               .blocks = ctoll(filer[0]),
               .freeafter = filer.size() == 2 ? ctoll(filer[1]) : 0
            };
         },
         std::views::iota(0),
         diskmap | std::views::chunk(2))
   | sr::to<vec<file>>();

   ll moveid = files[files.size()-1].fileid;
   while (moveid>0) {
      auto move_it = sr::find_if(files, [moveid](file it){ return it.fileid == moveid; });
      if (move_it==files.end()) break;
      auto free_it = std::find_if(files.begin(), move_it, [move_it](file it){ return it.freeafter >= move_it->blocks; });
      if (free_it!=files.end() && free_it->fileid != move_it->fileid) {
         //cout << "moving " << move_it->fileid << " after " << free_it->fileid << endl;
         std::prev(move_it)->freeafter += (move_it->blocks+move_it->freeafter);
         file new_file{
            .fileid = move_it->fileid,
            .blocks = move_it->blocks,
            .freeafter = free_it->freeafter-move_it->blocks
         };
         files.erase(move_it);
         free_it->freeafter=0;
         files.insert(std::next(free_it), new_file);
      }
      --moveid;
   }

   ll cs=0;
   ll index=0;
   for (auto f : files) {
      for (int i=0; i<f.blocks; ++i)
         cs+=f.fileid*index++;
      index+=f.freeafter;
   }

   return cs;
}

}
