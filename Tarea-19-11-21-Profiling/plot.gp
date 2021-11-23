set xlabel 'Block size';set ylabel 'Porcentajes de tiempo'
set term png; set out 'blocking.png'
set yrange [0:55]
set xrange [0:520]
plot 'bsize_total.txt'using 1:2  w l t 'Fill','bsize_total.txt' using 1:3  w l t 'Direct transpose', 'bsize_total.txt' using 1:4  w l t 'Cached transpose',	