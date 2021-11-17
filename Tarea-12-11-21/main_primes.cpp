# include <iostream>
# include <cstdlib>
# include "primes.h"

int main(int argc, char *argv[])
{
  const int n = std::atoi(argv[1]);
  
  std::cout << nthprime(n) << std::endl;
  
  return 0;
}
