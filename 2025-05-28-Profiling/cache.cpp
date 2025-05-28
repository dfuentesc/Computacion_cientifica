#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <iostream>

/*
  Tests cache misses.
*/

void option1(long * data, int m, int n);
void option2(long * data, int m, int n);
void option3(long * data, int m, int n);

int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);

  printf("Operating on matrix of size %ld by %ld\n", sI, sJ);
  auto start = std::chrono::steady_clock::now();
  long *arr = new long[sI*sJ]; // double array. 
  auto end = std::chrono::steady_clock::now();
  std::cout << (end-start).count() << "\n"; 

  // option 1
  auto start_o1 = std::chrono::steady_clock::now();
  option1(arr, sI, sJ);
  auto end_o1 = std::chrono::steady_clock::now();
  std::cout << (end_o1-start_o1).count() << "\n"; 
      
  auto start_o2 = std::chrono::steady_clock::now();
  option2(arr, sI, sJ);
  auto end_o2 = std::chrono::steady_clock::now();
  std::cout << (end_o2-start_o2).count() << "\n";

  // option 3

  auto start_o3 = std::chrono::steady_clock::now();
  option3(arr, sI, sJ);
  auto end_o3 = std::chrono::steady_clock::now();
  std::cout << (end_o3-start_o3).count() << "\n";

  // why this?
  printf("%ld\n", arr[0]);

  // free memory
  auto start_delete = std::chrono::steady_clock::now();
  delete [] arr; 
  auto end_delete = std::chrono::steady_clock::now();
  std::cout << (end_delete-start_delete).count() << "\n";
  return 0;
}

void option1(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(i * (n)) + j ] = i;
}

void option2(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(j * (m)) + i ] = i;
}

void option3(long * data, int m, int n)
{
  for (int i=0; i < m*n; ++i) data[i] = i;
}