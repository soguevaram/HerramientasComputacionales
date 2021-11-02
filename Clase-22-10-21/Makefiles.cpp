#include <iostream>
#include <cmath>
//Este programa compara la suma armonica realizada de
//dos formas diferentes para mostrar las diferencia
//computacionales

typedef float REAL; //Renombrar automaticamente
REAL sumup (int N);
REAL sumdown (int N);

int main (void)
{
  std::cout.precision(6);
  std::cout.setf(std::ios::scientific);

  for (int ii =1; ii < 1000; ++ii){
    REAL suma1 = sumup(ii);
    REAL suma2 = sumdown(ii);
    std::cout <<ii << "\t" << std::fabs(1 - suma1/suma2) << "\n";
  }
  return 0;
}

REAL sumup(int N)
{
  REAL suma=0;
  for (int ii = 1; ii <=N; ++ii){
    suma += 1.0/ii; //Hay que convertir en flotante para evitar
    //truncamiento
  }
  return suma;
}

REAL sumdown(int N)
{
  REAL suma=0;
  for (int ii = N; ii >=1; --ii){
    suma+= 1.0/ii;
  }
    return suma;
}
