#ifndef ALGORITHM_SIMPLESORT_HPP
#define ALGORITHM_SIMPLESORT_HPP

namespace algorithm {

template <class ForwardIterator>
auto simplesort(ForwardIterator first, ForwardIterator last) -> void
{
  for (auto i = first; std::next(i) != last; i++) {
    for (auto j = std::next(i); j != last; j++) {
      if (*j < *i) {
        std::swap(*i, *j);
      }
    }
  }
}

} // namespace algorithm

#endif // ALGORITHM_SIMPLESORT_HPP
