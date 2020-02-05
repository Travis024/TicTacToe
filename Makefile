CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: TicTacToe.o
	$(CXX) $(CXXFLAGS) TicTacToe.o -o TicTacToe

TicTacToe.o: TicTacToe.cpp
	$(CXX) $(CXXFLAGS) -c TicTacToe.cpp

clean:
	rm *.o TicTacToe
