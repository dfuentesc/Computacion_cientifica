all: main_factorial.x

%.x: %.o factorial.o
	g++ -fsanitize=address,undefined,leak $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ -fsanitize=address,undefined,leak -c $<

test: test_factorial.x
	./$< 

clean:
	rm -f *.o *.x a.out	