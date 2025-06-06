ARG1 ?= 4
ARG2 ?= 0.6

all: main_per.x
	bash script.sh	

%.x: %.o percolation.o
	spack load catch2; \
	g++ $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ -c $<

simul: main_per.x
	./main_per.x $(ARG1) $(ARG2)

test: test_per.x
	./$<

clean:
	rm -f *.o *.x a.out 