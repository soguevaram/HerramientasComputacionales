set term png
set output 'grafica.png'
set xlabel 'Tamaño de la matriz'
set ylabel 'Tiempo'
set logscale x
set logscale y
set title "Tiempo en función del tamaño de la matriz"
set yrange [0:200]
set xrange [100:3000]

plot 'parallel_datos.txt'w l t 'Datos'