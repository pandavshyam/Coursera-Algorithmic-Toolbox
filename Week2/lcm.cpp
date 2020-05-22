#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 0; l <= (long long) a * b; l = l + a)
    if (l % a == 0 && l % b == 0 && l != 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}