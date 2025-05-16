CXXFLAGS = -fsanitize=undefined,leak,address -fprofile-arcs -ftest-coverage

all: main_factorial.x

%.x: %.o factorial.o
	g++ $(CXXFLAGS) $^ -o $@ -l Catch2Main -l Catch2

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

test: test_factorial.x
	./$<

coverage: test_factorial.x
	./$<
	gcov factorial.cpp test_factorial.cpp
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage
	firefox coverage/index.html

clean:
	rm -f *.o *.x *.out *.gcov *.gcho *.gcda *~ a.out *.gcno