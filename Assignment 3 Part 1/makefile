TARGET = a4p1
SOURCES = a4p1.cpp HockeyList.h HockeyList.o ioutil.cpp ioutil.h
MODULES = $(SOURCES: .cpp = .o)
CPPFLAGS = -ansi -pedantic-errors -Wall -Wconversion

$(TARGET): clean $(MODUELS)
	g++ $(MODULES) $(CPPFLAGS) -o $(TARGET)

clean:
	/bin/rm  -rf $(TARGET) *. *~

all: 	clean $(TARGET)

.coo.o:
	g++ $(CPPFLAGS) -c $<
