#include <iostream>
#include <cstdlib>
#include <cmath>


int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array( double  data[], int  size);

int main (int argc, char **argv)
{
  int ii, jj;
  ii =  0;
  jj = -1;
  foo(ii, jj);
  foo(jj, ii);
  
  baz(25.9);
  
  const int NX = 2, NY = 3, NZ = 4;
  double *x,*y,*z; //Se corrige esto para poder inicializar los tamaños de los arreglos más adelante
  
  
  x = new double [NX];
  y = new double [NY];
  z = new double [NZ];
  //int ii, jj, kk;
  
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;
  
  // for (ii = 0; ii < NX; ++ii) {
  // x[jj] = ii;
  //}

  //Se elimina esta parte para que pueda tener la la misma funcionalidad pero en print array
  
  delete [] x; //Se elimina la memoria usada
  delete [] y;
  delete [] z;
  

  x = new double [NZ]; //Se vuelve a inicializar para que los arreglos puedan adquirir otro tamaño en las pŕoximas funciones
  y = new double [NY];
  z = new double [NZ+NY];

  print_array(x, NZ);
  print_array(y, NY);
  print_array(z, NZ + NY);
  std::cout << std::endl;
 
  for (jj = 0; jj < NY; ++jj) {
    x[jj] = ii;
    y[jj] = jj;
  }
  
  // print_array(x-NY, NY); 
  // print_array(y-NZ, NZ);
  // print_array(z + NZ + NY, NX);
  // std::cout << std::endl;

  //Se elimina esta parte ya que no tiene sentido el primer argumento de la función
  
  delete [] x; //Se elimina la memoria
  delete [] y;
  delete [] z;
  
  return EXIT_SUCCESS;
}


int foo(int a, int b)
{
  //Se añaden condicionales para evitar la división por cero
  int c=0;
  if (a !=0) {
    c += b/a;
  }
  if (b !=0) {
    c += a/b;
  }
  if (bar(a,b) !=0) {
    c += b/bar(a,b);
  }   
  // return a/b + b/bar(a, b) + b/a;
  return c;
}

int bar(int a, int b)
{
  unsigned int c = a;
  return c + a - b;
}

double baz(double x)
{
  if (x <= 0) return 0;
  //double v=1-(x+1);
  //Se añade este comentario ya que está sin uso
  return std::sqrt(x);
}

void print_array( double  data[], int  size)
{
  std::cout << std::endl;
  int ii=0;
  for (ii = 0; ii < size; ++ii) {
    data[ii] = ii;
    std::cout << data[ii] << "\n" ;
  }
}
