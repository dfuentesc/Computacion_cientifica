// imprima los numeros del 1 al 10 usando while
#include <iostream> 

// declaration
void print_numbers(int nmax);

int main(void) 
{
  int num;
    std::cout << "Please enter your number:" << std::endl;
    std::cin >> num;
    print_numbers(num);

  return 0;
}

// implementation
void print_numbers(int nmax)
{
  for (int n = 1; n <= nmax; n++) {
    std::cout << n << std::endl;
  } 
}