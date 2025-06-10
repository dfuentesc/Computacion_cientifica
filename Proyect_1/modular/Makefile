ARG1 ?= 4
ARG2 ?= 0.6

all: main_per.x
	bash script.sh
	bash resultados//graficas/script2.sh	

%.x: src/%.o src/percolation.o
	spack load catch2; \
	g++ $^ -o $@ -l Catch2Main -l Catch2

src/%.o: src/%.cpp
	g++ -c $< -Iinclude -o $@

simul: main_per.x
	./main_per.x $(ARG1) $(ARG2)

test: test_per.x
	./$<

report: report_per.x

clean:
	rm -f src/*.o *.x a.out 