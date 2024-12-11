// purpose: speed up development by introducing all includes, aliases, shorthands, etc
// in one convenient header.

#pragma once

// my lib includes
#include "filesystem/read_write_file.h"
#include "grid/all.h"
#include "printers/all.h"
#include "lang/exceptions.h"
#include "lang/equal_to.h"
#include "lang/less_than.h"
#include "lang/greater_than.h"
#include "string/replace.h"
#include "iterators/starts_with.h"
#include "string/split.h"
#include "string/trim.h"
#include "laws/set_difference.h"
#include "laws/set_intersection.h"
#include "tools/sets_intersection.h"
#include "tools/add_to_tally.h"
#include "tools/sort_map_by_value.h"
#include "iterators/find_subsequence.h"
#include "iterators/repeated_ranges.h"
#include "iterators/circular_next.h"

// abseil includes
#include <absl/algorithm/container.h>
#include <absl/utility/utility.h>
#include <absl/strings/str_split.h>
#include <absl/strings/str_replace.h>

// range-v3
#include <range/v3/all.hpp>

// stdlib includes
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <ranges>
#include <limits>

// std lib aliases
template<typename T> using uset = std::unordered_set<T>;
template<typename T> using mset = std::multiset<T>;
template<typename T> using set = std::set<T>;
template<typename T> using stack = std::stack<T>;
template<typename T, typename U> using umap = std::unordered_map<T, U>;
template<typename T, typename U> using mmap = std::multimap<T, U>;
template<typename T, typename U> using map = std::map<T, U>;
template<typename T> using vec = std::vector<T>;
template<typename T, typename U> using pair = std::pair<T, U>;
template<typename T> using qu = std::queue<T>;
template<typename T> using pqu = std::priority_queue<T>;
using std::string;
using std::string_view;
using std::cout;
using std::endl;
using std::stoll;
using std::find_if;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::distance;
using std::accumulate;
template<typename T> using opt = std::optional<T>;
using std::nullopt;

using ll = long long;
static ll max_ll = std::numeric_limits<long long>::max();
static ll min_ll = std::numeric_limits<long long>::min();

// ranges and views from both std and range-v3
namespace sr = std::ranges;
namespace sv = std::ranges::views;
namespace r3 = ranges;
namespace v3 = ranges::views;

// mzlib aliases
using usc = std::unordered_set<mzlib::grid::cell>;
template<typename T> using gridt = mzlib::grid::type<T>;
using mzlib::grid::cell;
namespace grid = mzlib::grid;
using mzlib::direction;
using mzlib::read_file_lines;
using mzlib::print;
using mzlib::string_replace;
using mzlib::starts_with_c;
using mzlib::split;
using mzlib::trim;
using mzlib::sets_intersection;
using mzlib::less_than;
using mzlib::greater_than;
using mzlib::equal_to;
using mzlib::add_to_tally;
using mzlib::sort_map_by_value;
using mzlib::find_subsequence;
using mzlib::repeated_sequences;
using mzlib::circular_next_iterator;

// tools reusable in aoc24
// future additions to my lib, perhaps

// common converters and predicated for range transformations, filtering, etc

inline ll strv_to_ll(std::string_view s) { return stoll(s.data()); }

inline ll str_to_ll(std::string s) { return stoll(s); }

template<typename Collection>
typename Collection::value_type
mul_all(const Collection& c) {
   return ranges::fold_left(c, 1, std::multiplies<>());
}

// collection size equals
template<long long Size, typename Collection>
bool
size_eq(const Collection& c) {
   return c.size() == Size;
}

// obnoxious!
inline string ctos(char c) { return string(1, c); }

// obsolete
inline ll ctoll(char c) {
   ll r =c-'0';
   if (r>9 || r<0) throw;
   return r;
}

template<std::integral I>
I cto(const char c) {
   I r = c-'0';
   if (r>9 || r<0) throw;
   return r;
}

inline char
get_first_digit(const string& line)
{
   auto first_digit = line
      | std::views::filter(isdigit)
      | std::views::take(1);

   return first_digit.front();
}

inline char
get_last_digit(const string& line)
{
   auto first_digit = line
      | std::views::reverse
      | std::views::filter(isdigit)
      | std::views::take(1);

   return first_digit.front();
}

inline const map<string, string>&
name_to_digit()
{
   static map<string, string> digit_names = {
      {"zero", "0"},
      {"one", "1"},
      {"two", "2"},
      {"three", "3"},
      {"four", "4"},
      {"five", "5"},
      {"six", "6"},
      {"seven", "7"},
      {"eight", "8"},
      {"nine", "9"}};

   return digit_names;
}

inline bool
any_key_starts_with(
   const map<string, string>& m,
   const string& s)
{
   auto such_keys = m
      | std::views::keys
      | std::views::filter([&s](const string& key) {
         return key.starts_with(s);
      });

   return !such_keys.empty();
}

template<typename T, ll Columns>
vec<vec<T>> numbers_in_columns(vec<string> input) {
   vec<vec<T>> values(Columns, vec<T>());
   for (auto line : input) {
      auto numbers_in_line = split(line, " ");
      for (int i=0; i<Columns; ++i)
         values[i].push_back(strv_to_ll(numbers_in_line[i]));
   }
   return values;
}

namespace mzlib
{

template <typename First, typename Second>
std::ostream&
print (
   const std::tuple<First, Second>& p,
   mzlib::print_parameters params = mzlib::print_parameters()
)
{
   params.stream << "[";
   print(std::get<0>(p), params) << ",";
   print(std::get<1>(p), params) << "]" << std::endl;
   return params.stream;
}

}

template <typename T>
T abs_minus(T a, T b)
{
   return std::abs(a-b);
}

// the following tuple operations looks stupid but are handy with ranges
template <typename T>
T difference_tuple(std::tuple<T, T> t)
{
   return std::abs(std::get<0>(t)-std::get<1>(t));
}

template <typename T>
T multiply_tuple(std::tuple<T, T> t)
{
   return std::get<0>(t)*std::get<1>(t);
}
// end of tuple ops

inline int
direction_to_degrees (direction d) {
   static map<direction, int> degrees{
         {direction::n, 0},
         {direction::ne, 45},
         {direction::e, 90},
         {direction::se, 135},
         {direction::s, 180},
         {direction::sw, 225},
         {direction::w, 270},
         {direction::nw, 315},
      };
   return degrees[d];
}

inline direction
degrees_to_direction (int d) {
   static map<int, direction> degrees{
            {0, direction::n},
            {45, direction::ne},
            {90, direction::e},
            {135, direction::se},
            {180, direction::s},
            {225, direction::sw},
            {270, direction::w},
            {315, direction::nw},
         };
   return degrees[d];
}

inline direction
turn(direction current, int degrees) {
   return degrees_to_direction(direction_to_degrees(current)+degrees);
}

// vec<string> parts = absl::StrSplit(input, absl::ByAnyChar("|"), absl::SkipEmpty());

namespace std
{

template <typename First, typename Second>
struct hash<pair<First, Second>>
{
   size_t
   operator() (const pair<First, Second>& p) const noexcept
   {
      size_t h = 112358;
      ::mzlib::hash_combine(h, p.first);
      ::mzlib::hash_combine(h, p.second);
      return h;
   }
};

}

inline
ll try_mul(ll a, ll b) {
   ll x = a * b;
   if (a != 0 && x / a != b) {
      throw mzlib::exception::out_of_range();
   }
   return x;
}

inline
ll try_add(ll a, ll b)
{
   if (a >= 0) {
      if (std::numeric_limits<ll>::max() - a < b) {
         throw mzlib::exception::out_of_range();
      }
   }
   else {
      if (b < std::numeric_limits<ll>::min() - a) {
         throw mzlib::exception::out_of_range();
      }
   }
   return a + b;
}

template <typename Iterator>
requires (
   mzlib::iterator<Iterator>
)
std::ostream&
print (
   const Iterator& begin,
   const Iterator& end,
   mzlib::print_parameters params = mzlib::print_parameters()
)
{
   bool first = true;
   params.stream << "[";
   for (auto it=begin; it<end; ++it)
   {
      if (!first)
         params.stream << ",";
      first = false;
      print(*it, params);
   }
   params.stream << "]" << std::endl;

   return params.stream;
}

// purpose: when couting from recursive functions it gets confusing without indent
class ind {
public:
   ind(int level, char ch = ' ') :
      l(level),
      c(ch)
   {}

private:
   int l;
   char c;

   friend std::ostream& operator<< (std::ostream& os, ind i);
};

inline
std::ostream&
operator<< (
   std::ostream& os,
   ind i)
{
   while (i.l--) os << i.c;
   return os;
}

namespace mzlib::grid
{

template <typename T>
std::vector<mzlib::grid::cell>
get_cells_line_segment (
   const mzlib::grid::type<T>& field,
   const cell& from,
   const cell& to
)
{
   std::vector<mzlib::grid::cell> segment;
   if (from != to) {
      const auto increment = to-from;
      cell c = to;
      while (grid::is_in(field, c)) {
         segment.push_back(c);
         c += increment;
      }
   }
   return segment;
}

template <typename T>
std::set<mzlib::grid::cell>
get_collinear_cells (
   const mzlib::grid::type<T>& field,
   const cell& cell1,
   const cell& cell2
)
{
   std::set<mzlib::grid::cell> collinear;
   if (cell1 != cell2) {
      const auto from_1_to_2 = get_cells_line_segment(field, cell1, cell2);
      const auto from_2_to_1 = get_cells_line_segment(field, cell2, cell1);
      collinear.insert(from_1_to_2.begin(), from_1_to_2.end());
      collinear.insert(from_2_to_1.begin(), from_2_to_1.end());
   }
   return collinear;
}

template <typename T>
bool
destination_exactly_one_larger (
   const grid::type<T>& grid,
   const cell& from,
   const cell& to
)
{
   return grid::access(grid, to) - 1 == grid::access(grid, from);
}

}