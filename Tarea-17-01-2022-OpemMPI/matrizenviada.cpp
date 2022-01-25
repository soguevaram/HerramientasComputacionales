#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

int printdata(std::vector<double> data,int N,int Nlocal);
double printtime(double total_time, int NP);

int main(int argc, char **argv)
{
  /* MPI Variables */
  int NP, pid;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &NP);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  const int N = std::atoi(argv[1]);
  int tag=0;
  double Nlocal=N/NP;
  MPI_Status status;

  //Declaracion matriz
  std::vector<double> data(Nlocal*N);
  std::fill(data.begin(), data.end(), 0.0);

  //Division de la matriz
  for(int ilocal = 0; ilocal < Nlocal; ++ilocal) {
    int jlocal = Nlocal*pid+ilocal;
    data[ilocal*N + jlocal] = 1.0;
  }
  
  //Proceso de los pid
  if (0==pid){
    printdata(data, N, Nlocal);
    for(int ipid = 1; ipidn < NP; ++ipid) {
      double tstart = MPI_Wtime();
      MPI_Recv(&data[0], N*Nlocal, MPI_DOUBLE , ipid, tag , MPI_COMM_WORLD, &status);
      double tend = MPI_Wtime();
      double total_time= tend - tstart;
      printdata(data, N, Nlocal);
    
      double prom=0.0;

      for(int ii=1; ii < NP; ii++){
	double banda=N*Nlocal*sizeof(double)/total_time/1.0e6;
	prom += banda;
      }
      prom=prom/(NP-1);
      std::cout << "Promedio de ancho de banda:" << prom << "MB/s" << std::endl;
				       
    }
  }
  
  else {
    MPI_Send(&data[0], N*Nlocal , MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}

int printdata(std::vector<double> data,int N,int Nlocal)
{  
  //Impresion de la matriz
  for (int i = 0; i < Nlocal; ++i){
    for (int j = 0; j < N; ++j)
      std:: cout << data[N*i+j] << ' ';
    std::cout << std::endl;
  }
  return 0;
}

double printtime(double total_time, int NP)
{
  //Impresion del tiempo
  std::cout  << "Time:"<< "\t" << total_time/NP <<   std::endl;
  return 0;
}
