all: main
CXXFLAGS=-Wall -g
CXX=g++
main: main.o Hardware_Classes.o
	$(CXX) -o $@ $^
clean:
	rm -f *.o *.exe
