#include <iostream>
#include <cstdlib>
#include <cmath>
double foo(double a, double b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size, const std::string& name);

int main (int argc, char **argv)
{
  int ii, jj;
  ii = 2;
  jj = -1;

  std::cout << "ii : " << ii << std::endl;
  std::cout << "jj : " << jj << std::endl;
  std::cout << "foo (ii,jj) : "  << foo(ii,jj) << std::endl;
  std::cout << "foo (jj,ii) : "  << foo(jj,ii) << std::endl;
  std::cout << "baz(25.9) : "  << baz(25.9) << std::endl;
  std::cout << std::endl;

  const int NX = 2, NY = 3, NZ = 4;
  double *x, y[NY] , z[NZ];
  x = new double [NX];
 std::cout << "arreglos x[], y[] y z[] creados pero no inicializados a 0, por lo tanto obtenemos datos basura "<< std::endl;
  print_array(x, NX,"x");
  print_array(y, NY,"y");
  print_array(z, NZ,"z");
  std::cout << std::endl;
  

  for (ii = 0; ii < NX; ++ii) {
    x[ii] = ii;
  }
   std::cout << "Solo guardamos datos en el arreglo x[] "<< std::endl;
  print_array(x, NX , "x");
  print_array(y, NY , "y");
  print_array(z, NZ , "z");
  std::cout << std::endl;
 
  for (ii = 0; ii < NY; ++ii) {
    y[ii] = ii;
  }
  for (ii = 0; ii < NZ; ++ii) {
    z[ii] = ii;
  }
  std::cout << "Guardamos datos en los arreglos faltantes y[] y z[] "<< std::endl;
  print_array(x, NX , "x");
  print_array(y, NY , "y");
  print_array(z, NZ , "z");
  std::cout << std::endl;

  delete [] x;
  return EXIT_SUCCESS;
}

double foo(double a, double b)
{
  return a/b + b/bar(a, b) + b/a;

}

int bar(int a, int b)
{
  unsigned int c = a;
  return c + a - b;
}

double baz(double x)
{
  if (x < 0){
  double x = -1*(x);
  }
  return std::sqrt(x);
}

void print_array(const double data[], const int & size ,const std::string& name)
{
  std::cout << name << "[]" << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
  std::cout << std::endl;
}
