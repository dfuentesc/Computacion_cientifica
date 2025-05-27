rm *.txt
parallel 'c++ Fibonacci.cpp -o {1}_{2}.out -O0' ::: 5 10 15 20 25 30 35 40 45 50 ::: 0 1 2 3 fast
parallel './{1}_{2}.out {1} >> {2}.txt' ::: 5 10 15 20 25 30 35 40 45 50 ::: 0 1 2 3 fast
rm *.out 

# saca el valor del tiempo de n = 20 para optimización 0

divisor=$(awk 'NR==4 {print $2}' 0.txt)
export divisor

parallel ' awk -v d="$divisor" "{ printf \"%d %.6f %.6f\\n\", \$1, \$2/d, \$3/d}" {}.txt > {}.txt.tmp && mv {}.txt.tmp {}.txt' ::: 0 1 2 3 fast

gnuplot << EOF
set terminal pngcairo enhanced font "Arial,12" size 1280,720
set output 'comparacion_optimizaciones.pdf'
set title "Comparación de Tiempos de Fibonacci por Optimización"
set xlabel "n"
set ylabel "Tiempo (s)"
set grid
set key left top
set logscale y

# Estilos para cada optimización
set style line 1 lc rgb "#FF0000" lt 1 lw 2 pt 7 ps 0.5  # O0
set style line 2 lc rgb "#00FF00" lt 1 lw 2 pt 7 ps 0.5  # O1
set style line 3 lc rgb "#0000FF" lt 1 lw 2 pt 7 ps 0.5  # O2
set style line 4 lc rgb "#FF00FF" lt 1 lw 2 pt 7 ps 0.5  # O3
set style line 5 lc rgb "#FFA500" lt 1 lw 2 pt 7 ps 0.5  # Ofast

set macros
legend = "keyentry title 'Función lenta' with linespoints lt 1"
legend_fast = "keyentry title 'Función rápida' with linespoints lt 2"

plot \
    '0.txt' using 1:2 with linespoints ls 1 title 'O0 (lenta)', \
    '0.txt' using 1:3 with linespoints ls 1 dt 2 title 'O0 (rápida)', \
    '1.txt' using 1:2 with linespoints ls 2 title 'O1 (lenta)', \
    '1.txt' using 1:3 with linespoints ls 2 dt 2 title 'O1 (rápida)', \
    '2.txt' using 1:2 with linespoints ls 3 title 'O2 (lenta)', \
    '2.txt' using 1:3 with linespoints ls 3 dt 2 title 'O2 (rápida)', \
    '3.txt' using 1:2 with linespoints ls 4 title 'O3 (lenta)', \
    '3.txt' using 1:3 with linespoints ls 4 dt 2 title 'O3 (rápida)', \
    'fast.txt' using 1:2 with linespoints ls 5 title 'Ofast (lenta)', \
    'fast.txt' using 1:3 with linespoints ls 5 dt 2 title 'Ofast (rápida)'

EOF


