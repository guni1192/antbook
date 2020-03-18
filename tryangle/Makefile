CC=g++-9
CPP=c++17
CPP_HEADER=/usr/local/Cellar/gcc/9.2.0_3/include/c++/9.2.0/x86_64-apple-darwin18/

run: build
	./solve

build: *.cpp
	$(CC) main.cpp -o solve -W -Wall -std=$(CPP)
