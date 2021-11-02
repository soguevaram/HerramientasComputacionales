#include <iostream>
#include <cmath>
//Este programa compara la suma armonica realizada de
//tres formas diferentes para mostrar las diferencia
//computacional

typedef double REAL; //Renombrar automaticamente
REAL sumaalterna (int N);
REAL sumaconrestas (int N);
REAL sumasinrestas (int N);

int main (void)
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  for (int ii =1; ii < 100; ++ii){
    REAL alterna = sumaalterna(ii);
    REAL conrestas = sumaconrestas(ii);
    REAL sinrestas = sumasinrestas(ii);
    std::cout <<ii << "\t" << std::fabs(1.0 - (alterna/sinrestas)) << "\t" << std::fabs(1.0 - (conrestas/sinrestas)) << "\n";
   
  }
  return 0;
}

REAL sumaalterna(int N)
{
  REAL suma=0;
  REAL y=0;
  for (int ii = 1; ii <=2*N; ++ii){
    y = (std::pow(-1.0,ii))*(ii/(ii+1.0));
    suma+=y;
    
  }
  return suma;
}

REAL sumaconrestas(int N)
{
  REAL suma=0;
  REAL p=0;
  REAL n=0;
  for (int ii = 1; ii <=N; ++ii){
    p += ((2.0*ii)/((2.0*ii)+1.0));
    n += (((2.0*ii)-1)/(2.0*ii));
  }
  return (p-n);
}

REAL sumasinrestas(int N)
{
  REAL suma=0;
  REAL y=0;
  for (int ii = 1; ii <=N; ++ii){
    y = ((1.0)/((2.0*ii)*((2.0*ii)+1.0)));
    suma += y;
  }
    return suma;
}

