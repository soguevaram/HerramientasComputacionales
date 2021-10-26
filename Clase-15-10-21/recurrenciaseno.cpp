// calcular el sin(x = pi/3), usando la expansion matematica
// sin(x, N) = \sum_{n=1}^{N} (-1)^{n-1} x^{2n-1}/(2n-1)!

#include <iostream>
#include <cmath>

double mysin(double x, int N); // declaration

int main()
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);
  
  const double x = M_PI/3;
  const double exact = std::sin(x);
  
  for (int n=1 ; n <=100  ; n++) {
    double diff = std::fabs(mysin(x, n) - exact)/exact;
    std::cout << n << "\t" << diff << "\n";
  }
  
  return 0;
}


double mysin(double x0, int N) // implementation
{
  const double x = M_PI/3;
  double a0 = std::pow(-1,0)*std::pow(x,2*0+1)/(2*0+1);
  double a1=0;
  double sum=0;
  
  for(int n=0;n<=N-1;n++){
    a1=a0*((-std::pow(x,2))/((2*n+3)*(2*n+2)));
    if(n==0){
	a1=a1+a0;
    }
	a0=a0*((-std::pow(x,2))/((2*n+3)*(2*n+2)));
	sum+=a1;
    } 
    return sum;
  }
