all: main

main:
	g++ main.cpp -g -std=c++11 -o main.exe
	

clean:
	rm -rf *.exe