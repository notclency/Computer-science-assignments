TARGET = asg2
SOURCES = teams.cpp ioutil.h ioutil.cpp teamList.h teamList.cpp
MODULES = $(SOURCES: .cpp = .o)
TESTS = test_insert
TEST_MODULES = test.o teamList.o
CPPFLAGS = -ansi -pedantic-errors -Wall -Wconversion

GTFLAGS = -lgtest -lgtest_main

$(TARGET): clean $(MODULES)
	g++ $(MODULES) -o $(TARGET)

clean:
	/bin/rm -rf *.o $(TARGET)  *. *~

all:	clean $(TARGET)


.cpp.o:
	g++ $(CPPFLAGS) -c $<

TEST:	$(TEST_MODULES)
	g++ $(GTFLAGS) $(CPPFLAGS) $(TEST_MODULES) -o $(TESTS)
	./(TESTS)
