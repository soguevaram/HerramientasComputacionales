# include <iostream>
# include <cstdlib>
# include <cmath>
# include <cassert>

int isprime(int m);
int nthprime(int n);
void test_factorial(void);

int main(int argc, char *argv[])
{
  test_factorial();
  const int n = std::atoi(argv[1]);
  std::cout << nthprime(n) << "\n";
  
  return 0;
}


int isprime(int m)
{
  if (m==1) return 0; 
  int result=1;
  for(int ii = 2;ii <= std::pow(m,0.5); ++ii) {
    if (m%ii == 0){ 
      result = 0;
      break;
    }
  }
  return result;
}
int nthprime(int n)
{
  int counter = 0;
  for (int ii = 2; ; ++ii) {
    counter += isprime(ii);
    if (counter==n)
      return ii;
  }
}

void test_factorial(void)
{
  std::cout << "Probando que isprime(2) == 1" << std::endl;
  assert(isprime(2) == 1);
  std::cout << "Probando que isprime(1) == 0" << std::endl;
  assert(isprime(1) == 0);
  std::cout << "Probando que isprime(3) == 1" << std::endl;
  assert(isprime(3) == 1);
  std::cout << "Probando que isprime(10) == 0" << std::endl;
  assert(isprime(10) == 0);
  std::cout << "Probando que isprime(15485863) == 1" << std::endl;
  assert(isprime(15485863) == 1);
  std::cout << "Probando que isprime(179424673) == 1" << std::endl;
  assert(isprime(179424673) == 1);
  std::cout << "Probando que isprime(179424674) == 0" << std::endl;
  assert(isprime(179424674) == 0);
  std::cout << "Probando que nthprime(2) == 3" << std::endl;
  assert(nthprime(2) == 3);
  std::cout << "Probando que nthprime(3) == 5" << std::endl;
  assert(nthprime(3) == 5);
  std::cout << "Probando que nthprime(7) == 17"<< std::endl;
  assert(nthprime(7) == 17);
  std::cout << "Probando que nthprime(5) == 11"<< std::endl;
  assert(nthprime(5) == 11);
  std::cout << "Probando que nthprime(97) == 509"<< std::endl;
  assert(nthprime(97) == 509);
  std::cout << "Probando que nthprime(156) == 911" << std::endl;
  assert(nthprime(156) == 911);
}

