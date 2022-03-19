all: a.out run

a.out: main.cpp
	@g++ main.cpp -O2 -fno-asm -Wall -lm -static -std=c++11 -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive

run:
	@echo "======Running======"
	@./a.out
	@echo "========End========"

clean:
	rm a.out

.PHONY: clean
