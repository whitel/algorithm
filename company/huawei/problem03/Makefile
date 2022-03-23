all: a.out run

a.out: main.cpp
	@g++ main.cpp -O2 -fno-asm -lm -static -std=c++11 -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive

run:
	@echo "======Input======="
	@cat inputdata
	@echo "======Output======"
	@./a.out < inputdata

clean:
	rm a.out

.PHONY: clean
