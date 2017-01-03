#ifndef ALGORITHM_FIBONACCI_HPP
#define ALGORITHM_FIBONACCI_HPP

namespace algorithm {

auto fibonacci(int n) -> int
{
  if (n == 0 || n == 1) return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

auto memorized_fibonacci(int n) -> int
{
  static int memo[10000] = {};

  if (n == 0 || n == 1) {
    return n;
  }

  int m = memo[n];
  if (m != 0) {
    return m;
  } else {
    return memo[n] = memorized_fibonacci(n - 1) + memorized_fibonacci(n - 2);
  }
}

auto dp_fibonacci(int n) -> int
{
  static int memo[10000] = {};

  memo[0] = 0; memo[1] = 1;
  for (int i = 2; i <= n; i++) {
    memo[i] = memo[i - 1] + memo[i - 2];
  }
  return memo[n];
}

} // namespace algorithm

#endif // ALGORITHM_FIBONACCI_HPP
