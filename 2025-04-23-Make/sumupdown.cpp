#include <iostream>
#include <cmath>

typedef float REAL; 

REAL sumup(int nterms);
REAL sumdown(int nterms);

int main(int argc, char **argv)
{
  std::cout.precision(6); std::cout.setf(std::ios::scientific);
  for (int ii = 1; ii <= 10000; ++ii) {
    REAL sum1 = sumup(ii);
    REAL sum2 = sumdown(ii);
    std::cout << ii << "\t" << sum1 << "\t" << sum2
              << "\t" << std::fabs(sum1-sum2)/sum2 << "\n";
  }

  return 0;
}

REAL sumup(int nterms)
{
    // todo
    REAL result = 0.0;
    for (int n = 1; n <= nterms; n++) {
        result += 1.0/n;
    }
    return result;
}

REAL sumdown(int nterms)
{
    REAL result = 0.0;
    for (int n = nterms; n >= 1; n--) {
        result += 1.0/n;
    }
    return result;
}