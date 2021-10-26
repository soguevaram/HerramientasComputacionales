// calcular el sin(x = pi/3), usando la expansion matematica
// sin(x, N) = \sum_{n=1}^{N} (-1)^{n-1} x^{2n-1}/(2n-1)!

#include <iostream>
#include <cmath>

double mysin(double x, int N); // declaration
int factorial(int n);

int main()
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);
  
  const double x = M_PI/3;
  const double exact = std::sin(x);

    for (int n=1 ; n <=  30   ; n++) {
    double diff = std::fabs(mysin(x, n) - exact)/exact;
    std::cout << n << "\t" << diff << "\n";
  }
  
  return 0;
}

int factorial(int n)
{
  if (n<0) return 0;
  else if (n>1) return n*factorial(n-1);
  return 1;
}


double mysin(double x0, int N) // implementation
{
  double p=0;
  double m=0;
  const double x = M_PI/3;
  for(int n=1;n<=N;n++){
    double y = std::pow(-1,n-1)*pow(x,2*n-1)/factorial(2*n-1);
     p += y;
  }
  return p;
}
