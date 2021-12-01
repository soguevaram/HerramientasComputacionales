set term png
set output 'scaling.png'
set xlabel 'Número de threads'
set ylabel 'Escalamiento del wall time'
set title "Escalamiento con computador de 12 threads"
set yrange [0:14]
set xrange [0:17]

plot 'nuevos_eigen.txt'w l t 'Escalamiento eigen' , \
     'nuevos_blas.txt' w l t 'Escalamiento eigen con blas