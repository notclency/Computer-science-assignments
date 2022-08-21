TARGET = a4p2
SOURCES = a4p2.cpp HockeyList.h HockeyList.cpp ioutil.cpp ioutil.h
MODULES = $(SOURCES: .cpp = .o)
CPPFLAGS = -ansi -pedantic-errors -Wall -Wconversion

$(TARGET): clean $(MODULES)
	g++ $(MODULES) $(CPPFLAGS) -o $(TARGET)

clean:
	/bin/rm -rf $(TARGET) *. *~ *.o

all:	clean $(TARGET)

.coo.o:
	g++ $(CPPFLAGS) -c $<
