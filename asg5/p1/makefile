TESTS = test_Grid
SOURCES = test_Grid.cpp Grid.cpp globals.h Grid.h
MODULES = Grid.o
CPPFAGS = -ansi -pedantic-errors -Wall -Wconversion -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage
GCOVFILE = Grid
GTFLAGS = -lgtest -lpthread -lgtest_main

$(TESTS): $(TESTS).o Grid.o
	g++ $(TESTS).o Grid.o $(GCOVFLAGS) $(GTFLAGS) -o $(TESTS)
	./$(TESTS)
	gcov $(GCOVFILE).cpp 2> /dev/null | grep -A 1 $(GCOVFILE).cpp
clean:
	/bin/rm -f *.o $(TESTS) *.*~ *.g*

all:	clean $(TESTS)

Grid.o: Grid.cpp globals.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Grid.cpp 

$(TESTS).o: test_Grid.cpp globals.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTS).cpp
