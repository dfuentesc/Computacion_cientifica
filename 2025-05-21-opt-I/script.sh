for OPT in 0 1 2 3; do
    gcc -O$OPT transpose_blocking.c
    MSIZE=512; 
    for ((csize=1; csize <= $MSIZE; csize *= 2)); do 
    echo -n $MSIZE $csize " ";
     ./a.out $MSIZE $csize; 
    done > data-$OPT.txt
done
