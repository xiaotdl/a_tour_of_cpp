# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

test: test.o
	$(CXX) $(CXXFLAGS) -o test test.o

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp
