rm *.txt
make clean
make

parallel -j 4 './main_per.x {1} {2} >> data.txt' ::: $(seq 10 1 100) ::: $(seq -f "%.2f" 0.10 0.01 0.90)
sort -n -k1,1 data.txt -o data.txt

#parallel './main_per.x {2} {1} >> data.txt' ::: 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 ::: 10 15 20 25 30 35
rm *.x