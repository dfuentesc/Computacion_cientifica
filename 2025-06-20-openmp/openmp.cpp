#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
  std::cout << "BEFORE\n";
#pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    std::cout << "Hola mundo, desde el thread " << tid << ", from " << nth << std::endl;
  }
  std::cout << "AFTER\n";

  return 0;
}