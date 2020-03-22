CC=g++-9
CPP=c++17

run: build
	./solve < input.txt

build: *.cpp
	$(CC) main.cpp -o solve -W -Wall -std=$(CPP)
