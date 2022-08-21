RUN = paint
SOURCES = main.cpp Grid.cpp Grid.h Shape.cpp Shape.h Shape_Collection.cpp Shape_Collection.h Rectangle.cpp Rectangle.h Square.cpp Square.h IsoTriangle.cpp IsoTriangle.h EquTriangle.cpp EquTriangle.h ioutil.cpp ioutil.h
MODULES = $(SOURCES: .cpp = .o)
CPPFLAGS = -ansi -pedantic-errors -Wall -Wconversion -g

$(RUN): $(MODULES)
	g++ $(MODULES) $(CPPFLAGS) -o $(RUN)

clean:
	/bin/rm -f *.o $(TESTS) $(RUN) *.*~ *.g*

all:	clean $(RUN)
	./$(RUN)
