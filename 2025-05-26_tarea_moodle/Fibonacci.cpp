#include <iostream>
#include <chrono>
#include <cstdlib>

// Naive recursive Fibonacci
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long fi_fast(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}


int main(int argc, char **argv) {
    const int n = std::atoi(argv[1]);
    auto start1 = std::chrono::high_resolution_clock::now();
    long long result1 = fi_fast(n);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    
    auto start2 = std::chrono::high_resolution_clock::now();
    long long result2 = fib(n);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    //1.61e-07 es el valor del tiempo de n=20 para optimización 0

    std::cout << n << "\t" << elapsed2.count() << " \t" << elapsed1.count() << "\n";
    return 0;
}