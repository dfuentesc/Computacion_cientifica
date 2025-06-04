all: main_per.x 

%.x: %.o percolation.o
	g++ $^ -o $@ 

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o *.x a.out	