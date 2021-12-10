set table "/dev/null"
X=0
X_row=0
X_col=2
plot "datos.txt" using (($0==X_row)?(X=column(X_col),X):0)
unset table

#Ahora, sí, la gráfica:

set title 'Parralel'
set xlabel 'Number of threads'; set ylabel 'Parallel efficiency of time'
set grid
set term png; set out 'parallel.png'
plot 'datos.txt' u 1:(X/($1*$2)) w l t 'Parallel for a vector'