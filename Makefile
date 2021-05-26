all: clean
	g++ -std=c++11 -o simulator ex3.cpp
clean:
	rm -f simulator
.PHONY: all clean
