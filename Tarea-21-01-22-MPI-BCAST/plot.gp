set xlabel 'Array size';set ylabel 'Bandwidth'
set term pdf; set out 'MPI-Bandwidth.pdf'
set yrange [0:5000]
set title "Ancho de banda por dos métodos de MPI - 8 Cores"
plot 'data_mpi_bcast.txt'using 1:3  w l t 'MPI Send Receive','data_mpi.txt' using 1:3  w l t 'MPI Broadcast', 