all: main


main: 
	clang++ -g -o main src/main.cpp

clean: main
	rm main
