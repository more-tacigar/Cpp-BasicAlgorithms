#include <cassert>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm/quicksort.hpp>
#include <algorithm/mergesort.hpp>
#include <algorithm/binarysearch.hpp>
#include <algorithm/simplesort.hpp>
#include <algorithm/fibonacci.hpp>

template <class ForwardIterator>
void print(ForwardIterator first, ForwardIterator last)
{
  std::cout << "{ ";
  for (; first != last; first++) {
    std::cout << *first << " ";
  }
  std::cout << "}" << std::endl;
}

int main()
{
  std::vector<int> vector1 = { 10, 50, 20, 20, 70, 80, 40, 30, 10, 100, 10 };
  algorithm::quicksort(std::begin(vector1), std::end(vector1));
  print(std::begin(vector1), std::end(vector1));

  std::vector<int> vector2 = { 10, 50, 20, 20, 70, 80, 40, 30, 10, 100, 10 };
  algorithm::mergesort(std::begin(vector2), std::end(vector2));
  print(std::begin(vector2), std::end(vector2));

  std::vector<int> vector3 = { 10, 20, 20, 50, 60, 80, 90, 90, 90, 100 };
  assert(algorithm::binarysearch(std::begin(vector3), std::end(vector3), 40)
         == std::end(vector3));
  assert(algorithm::binarysearch(std::begin(vector3), std::end(vector3), 50)
         == std::begin(vector3) + 3);

  std::vector<int> vector4 = { 10, 50, 20, 20, 70, 80, 40, 30, 10, 100, 10 };
  algorithm::simplesort(std::begin(vector4), std::end(vector4));
  print(std::begin(vector4), std::end(vector4));

  assert(algorithm::fibonacci(10) == 55);
  assert(algorithm::memorized_fibonacci(10) == 55);
  assert(algorithm::dp_fibonacci(10) == 55);

  return 0;
}
