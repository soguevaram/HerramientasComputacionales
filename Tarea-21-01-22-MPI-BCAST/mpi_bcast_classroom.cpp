#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

void send_data_collective(int size, int pid, int np);

int main(int argc, char **argv)
{
  int np, pid;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  for (int SIZE=1; SIZE < 10000; SIZE++){
  send_data_collective(SIZE, pid, np);
  }

  MPI_Finalize();

  return 0;
}

void send_data_collective(int size, int pid, int np)
{
  MPI_Status status;
  // create data buffer (all processes)
  double * data = new double [size];
  int tag = 0;
  if (0 == 0){
  std::iota(data, data+size, 0.0); // llena como 0 1 2 3 4
  }
  double start = MPI_Wtime();
  
  if (0 == pid) {
    for (int pid=1; pid < np; ++pid){
      MPI_Send(&data[0], size, MPI_DOUBLE, pid, tag, MPI_COMM_WORLD);
    }
  }
  else{
    MPI_Recv(&data[0], size, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &status);
  }
    
  double end = MPI_Wtime();

  if (0 == pid) {
    int datasize = sizeof(double)*size;
    std::cout << datasize << "\t" << (end-start) << "\t"
	      << datasize/(end-start)/1.0e6 << "\n";
  }
  delete [] data;
}
