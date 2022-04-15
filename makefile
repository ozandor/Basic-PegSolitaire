hw2: main.o solitaire.o
	g++ main.o solitaire.o -o run

main.o: main.cpp
	g++ -c main.cpp

solitaire.o: solitaire.cpp
	g++ -c solitaire.cpp

clean:
	rm *.o run
