set term pdf
set out "sumupdown.pdf"
set log y
set xlabel "Nterms"
set ylabel "Percentual difference"
plot 'data.txt' u 1:4 w lp pt 4