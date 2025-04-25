#include <random>
#include <iostream>

int main(void)
{
  int seed = 1;
  std::mt19937 gen(seed);
  std::normal_distribution<> dis{1.5, 0.3};
  for(int n = 0; n < 100000; ++n) {
    std::cout << dis(gen) << std::endl;
  }
}