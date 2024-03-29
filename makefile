all:

clean:
	rm -f  *.gcda
	rm -f  *.gcno
	rm -f  *.gcov
	rm -f  TestGraph


config:
	doxygen -g

doc: Graph.h
	doxygen Doxyfile

Graph.log:
	git log > Graph.log



TestGraph: Graph.h TestGraph.c++
	g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Graph.h TestGraph.c++ -o TestGraph -lgtest -lgtest_main -lpthread

run: TestGraph
	./TestGraph

valgrind: TestGraph
	-valgrind ./TestGraph
coverage: run
	gcov-4.7 -b TestGraph.c++

