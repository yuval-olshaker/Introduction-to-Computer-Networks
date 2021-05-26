all: clean
	g++ -std=c++11 -o *.cpp
clean:
	rm -f ex3
.PHONY: all clean
