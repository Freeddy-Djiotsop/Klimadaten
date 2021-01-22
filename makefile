#Freeddy Djiotsop

clean: run
	rm -rf *.o

run: all
	./klima

all: main.o klima.o ausgabe.o
	g++ -Wall main.o klima.o ausgabe.o -o klima

main.o: main.cpp klima.hpp ausgabe.hpp
	g++ -Wall -c main.cpp

klima.o: klima.cpp klima.hpp ausgabe.hpp
	g++ -Wall -c klima.cpp

ausgabe.o: ausgabe.cpp ausgabe.hpp
	g++ -Wall -c ausgabe.cpp