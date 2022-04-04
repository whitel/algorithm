all: a.out run

a.out: main.cpp
	@g++ main.cpp -std=c++11 -w -pthread

run:
	@./a.out < inputdata

clean:
	rm a.out

.PHONY: clean
