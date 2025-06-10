cd reporte 
rm *.txt
parallel 'c++ Fibonacci.cpp -o {1}_{2}.out -O0' ::: 5 10 15 20 25 30 35 40 45 50 ::: 0 1 2 3 fast
parallel './{1}_{2}.out {1} >> {2}.txt' ::: 5 10 15 20 25 30 35 40 45 50 ::: 0 1 2 3 fast
rm *.out 



