#include <iostream>
#include <list>
#include <vector>
#include <algorithm/quicksort.hpp>

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
      
  return 0;
}
    
