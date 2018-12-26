# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date
#
test: test.o Vector.o Shape.o
	$(CXX) $(CXXFLAGS) -o test test.o Shape.o Vector.o

test.o: test.cpp Vector.h Shape.h
	$(CXX) $(CXXFLAGS) -c test.cpp

Vector.o: Vector.h Shape.h

Shape.o: Shape.h
