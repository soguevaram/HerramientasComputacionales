set xlabel 'N';set ylabel 'Diff %'
set term pdf; set out 'fig.pdf'
set yrange [0:0.0000000000001]
plot 'datos.txt'using 1:2  w l t 'Diferencia porcentual S1 con S3','datos.txt' using 1:3  w l t 'Diferencia porcentual S2 con S3'	