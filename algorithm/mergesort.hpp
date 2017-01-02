#ifndef ALGORITHM_MERGESORT_HPP
#define ALGORITHM_MERGESORT_HPP

#include <algorithm>
#include <iterator>
#include <vector>

namespace algorithm {

namespace detail {

// non-inplace merge algorithm.
template <class RandomAccessIterator>
auto merge(RandomAccessIterator first, RandomAccessIterator middle,
           RandomAccessIterator last)
{
  std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> tmp;
  auto i = first, j = middle + 1;
  while (i <= middle && j < last) {
    if (*i < *j) tmp.push_back(*(i++));
    else         tmp.push_back(*(j++));
  }
  if (i == middle + 1) {
    tmp.insert(std::end(tmp), j, last);
  } else {
    tmp.insert(std::end(tmp), i, middle + 1);
  }
  std::copy(std::begin(tmp), std::end(tmp), first);
}

} // namespace detail

template <class RandomAccessIterator>
auto mergesort(RandomAccessIterator first, RandomAccessIterator last) -> void
{
  if (first + 1 == last) return;
  auto middle = first + (last - 1 - first) / 2;
  
  mergesort(first, middle + 1);
  mergesort(middle + 1, last);
  detail::merge(first, middle, last); // or std::inplace_merge(...);
}

} // namespace algorithm

#endif // ALGORITHM_MERGESORT_HPP
