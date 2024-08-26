all: compile

compile: main.o funcTypesEquation.o debug.o release.o SolveEquation.o
	g++ main.o funcTypesEquation.o debug.o release.o SolveEquation.o -o out

main.o: cpp_files\main.cpp
	g++ -c cpp_files\main.cpp

funcTypesEquation.o: cpp_files\funcTypesEquation.cpp
	g++ -c cpp_files\funcTypesEquation.cpp

debug.o: cpp_files\debug.cpp
	g++ -c cpp_files\debug.cpp

release.o: cpp_files\release.cpp
	g++ -c cpp_files\release.cpp

SolveEquation.o: cpp_files\SolveEquation.cpp
	g++ -c cpp_files\SolveEquation.cpp

clean:
	rm -rf *.o compile
