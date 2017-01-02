#ifndef ALGORITHM_BINARYSEARCH_HPP
#define ALGORITHM_BINARYSEARCH_HPP

#include <functional>
#include <iterator>

namespace algorithm {

template <class RandomAccessIterator>
auto binarysearch(RandomAccessIterator first, RandomAccessIterator last,
                  typename std::iterator_traits<RandomAccessIterator>::value_type value)
    -> RandomAccessIterator
{
  std::function<RandomAccessIterator(int, int)>
      _binarySearch = [&](int imin, int imax) -> RandomAccessIterator {
    if (imin > imax) {
      return last;
    }
    auto imid = (imin + imax) / 2;
    if (first[imid] > value) {
      return _binarySearch(imin, imid - 1);
    } else if (first[imid] < value) {
      return _binarySearch(imid + 1, imax);
    } else {
      return first + imid;
    }
  };
  return _binarySearch(0, static_cast<int>(last - first) - 1);
}

} // namespace algorithm

#endif // ALGORITHM_BINARYSEARCH_HPP
