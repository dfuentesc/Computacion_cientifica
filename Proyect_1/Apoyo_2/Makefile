all: main_factorial.x

%.x: %.o factorial.o
	g++  $^ -o $@ 

%.o: %.cpp
	g++  $<

test: test_factorial.x
	./$< 

clean:
	rm -f *.o *.x a.out	