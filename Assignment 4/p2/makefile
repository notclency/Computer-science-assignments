test_Shape = test_Shape
test_Shape_Collection = test_Shape_Collection

SHAPE_SOURCES = Shape
SHAPE_COLLECTION_SOURCES = Shape_Collection

SHAPE_MODULES = test_Shape.o Shape.o Grid.o
SHAPE_COLLECTION_MODULES = test_Shape_Collection.o Shape_Collection.o Shape.o Grid.o

CPPFLAGS = -ansi -pedantic-errors -Wall -Wconversion -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage
GTFLAGS = -lgtest -lpthread -lgtest_main

SHAPE = Shape
SHAPE_COLLECTION = Shape_Collection

$(test_Shape): $(test_Shape).o Grid.o Shape.o
	g++ $(test_Shape).o Grid.o Shape.o $(GCOVFLAGS) $(CPPFLAGS) $(GTFLAGS) -o $(test_Shape)
	$(test_Shape)
	gcov $(SHAPE).cpp 2> /dev/null | grep -A 1 $(SHAPE).cpp

$(test_Shape_Collection): $(test_Shape_Collection).o Shape.o Grid.o Shape_Collection.o
	g++ $(test_Shape_Collection).o Shape.o Grid.o Shape_Collection.o $(GCOVFLAGS) $(CPPFLAGS) $(GTFLAGS) -o $(test_Shape_Collection)
	$(test_Shape_Collection)
	gcov $(SHAPE_COLLECTION).cpp 2> /dev/null | grep -A 1 $(SHAPE_COLLECTION).cpp

clean:
	/bin/rm -f *.o $(test_Shape) $(test_Shape_Collection) *.*~ *.g*

all:	clean $(test_Shape) $(test_Shape_Collection)

Grid.o: Grid.cpp globals.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Grid.cpp


Shape.o: Shape.cpp Shape.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Shape.cpp

Shape_Collection.o: Shape_Collection.cpp Shape_Collection.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Shape_Collection.cpp
