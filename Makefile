all: main
CXXFLAGS=-Wall -g
CXX=g++
main: main.o Win32_Processor.o
	$(CXX) -o $@ $^
clean:
	rm -f *.o *.exe
