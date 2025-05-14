all: main_factorial.x

%.x: %.o factorial.o
	g++ $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ -c $<

test: test_factorial.x
	./$< 

clean:
	rm -f *.o *.x a.out	