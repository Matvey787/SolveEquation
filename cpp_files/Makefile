all: compile

compile: main.o funcTypesEquation.o debug.o release.o SolveEquation.o
	g++ main.o funcTypesEquation.o debug.o release.o SolveEquation.o -o out

main.o: main.cpp
	g++ -c main.cpp

funcTypesEquation.o: funcTypesEquation.cpp
	g++ -c funcTypesEquation.cpp

debug.o: debug.cpp
	g++ -c debug.cpp

release.o: release.cpp
	g++ -c release.cpp

SolveEquation.o: SolveEquation.cpp
	g++ -c SolveEquation.cpp

clean:
	rm -rf *.o compile
