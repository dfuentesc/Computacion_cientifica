#include <random>
#include <iostream>
#include <cstdlib>

double compute_pi(int seed, long nsamples);

int main(int argc, char **argv) 
{
  const int SEED = std::atoi(argv[1]);
  const long NSAMPLES = std::atol(argv[2]);
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double mypi = compute_pi(SEED, NSAMPLES);
  std::cout << mypi << "\n"; 
    
  return 0;
}

double compute_pi(int seed, long nsamples) 
{
  // todo
  long Nc = 0;
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(-0.5, 0.5);
  for(int n = 0; n < nsamples; ++n) {
      double x = dis(gen);
      double y = dis(gen);
      if (x*x + y*y <= 0.25) {
          Nc++;
      }
  }
  return 4.0*Nc/nsamples;
}