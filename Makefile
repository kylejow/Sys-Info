all: main Win32_Processor
CXXFLAGS=-Wall -g
CXX=g++
main: main.o
	$(CXX) -o $@ $^
Win32_Processor: Win32_Processor.o
	$(CXX) -o $@ $^
clean:
	rm -f *.o *.exe
