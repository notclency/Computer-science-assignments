# This is  "Makefile". Notice that comments begin with "#"

TESTS = test_m_add

MODULES = test_m_add.o m_add.o

CPPFLAG = -ansi -pedantic-errors -Wall -Wconversion

GTFLAGS = -lgtest -lgtest_main

#-----------------------------------------------------------#

$(TESTS): $(MODULES)
	g++ $(GTFLAGS) $(CPPFLAGS) $(MODULES) -o $(TESTS)
	./$(TESTS)

clean:
	rm -rf *.out *~ $(TESTS)

all: clean $(TESTS)
