#ifndef ALGORITHM_QUICKSORT_HPP
#define ALGORITHM_QUICKSORT_HPP

namespace algorithm {

template <class BidirectionalIterator>
auto quicksort(BidirectionalIterator first, BidirectionalIterator last) -> void
{
  auto l = first, r = std::prev(last);
  while (l != r) {
    while (*l < *first)            l++;
    while (*r >= *first && l != r) r--;
    if (l != r) std::swap(*r, *l);
  }
  if (l != first)           quicksort(first, l);
  if (std::next(l) != last) quicksort(std::next(l), last);
}

} // namespace algorithm

#endif // ALGORITHM_QUICKSORT_HPP
