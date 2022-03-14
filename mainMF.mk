CXX=clang++-9 
CXXFLAGS=-std=c++2a -Werror

HEADERS=mat.hpp
OBJECTS=mat.o
SOURCES=mat.cpp

run: main 
	./$^

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test