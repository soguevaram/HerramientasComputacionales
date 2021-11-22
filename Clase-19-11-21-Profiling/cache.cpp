#include <cstdio>
#include <cstdlib> //Convertir string en enteros

/*
   Tests cache misses.
*/

int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]); //nFilas
  long sJ = atoi(argv[2]); //nColumnas

  printf("Operating on matrix of size %ld by %ld\n", sI, sJ); //sI se reemplaza en %ld y sJ se reemplaza en %ldn

  long *arr = new long[sI*sJ]; // double array. 2 dimensiones en 1

  // option 1 : Varian más rapido las columnas, de esta forma está almacenado 
  for (long i=0; i < sI; ++i)
    for (long j=0; j < sJ; ++j)
      arr[(i * (sJ)) + j ] = i;
  
  // option 2: Varian más rapido las filas
  for (long i=0; i < sI; ++i)
      for (long j=0; j < sJ; ++j)
         arr[(j * (sI)) + i ] = i;

  // option 3: Lo recorre linealmene¿te
  for (int i=0; i < sI*sJ; ++i) arr[i] = i;

  printf("%ld\n", arr[0]);
  
  return 0;
}
