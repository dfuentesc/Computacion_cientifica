#!/bin/bash
rm -f resultados/*.txt;
for i in {1..100};do
echo "Ejecutando iteración $i";
out="resultados/result_${i}.txt";
parallel -j 4 './main_per.x {1} {2}' ::: $(seq 10 1 100) ::: $(seq -f "%.2f" 0.10 0.01 0.90) >> ${out};
sort -n -k2,2 ${out} -o ${out};
done
awk '{
    print >> ("resultados/graficas/" $2 ".txt")
}' *.txt