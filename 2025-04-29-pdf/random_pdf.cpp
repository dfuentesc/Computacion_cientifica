#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atoi(argv[3]);
  const double SIGMA = std::atoi(argv[4]);
  const double XMIN = std::atoi(argv[5]);
  const double XMAX = std::atoi(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES,MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // TODO: histogram stuff

  std::vector<int> histogram(nbins, 0); 
  const double bin_width = (xmax - xmin) / nbins; 

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    if (r >= xmin && r < xmax) { 
        int bin_index = static_cast<int>((r - xmin) / bin_width);
        histogram[bin_index]++; 
    }
  }
  
    for (int i = 0; i < nbins; ++i) {
        double bin_center = xmin + (i + 0.5) * bin_width;
        double pdf = static_cast<double>(histogram[i]) / (nsamples * bin_width);
        std::cout << bin_center << "\t" << pdf << "\n";
    }

}
 // ./a.out 1 10000000 0 1 -1 1 50 > seed_1.txt
 // ./a.out 2 10000000 0 1 -1 1 50 > seed_2.txt
 // ./a.out 5 10000000 0 1 -1 1 50 > seed_5.txt