/*
Travis Torline and Chris Gilbert

This program creates a simple two-player game to Tic-Tac-Toe
Users are asked to input the desired location of their mark
A winner is determined by who gets three in a row

No arguments are required to run this program.
*/

#include <iostream>
#include <string>
#include <vector>

//Creates an empty board for the TicTacToe game to be played on
void CreateBoard(char game_board[3][3]);
void DisplayBoard(char game_board[3][3]);

//Prints the board to the screen so players can see it
void DisplayBoard(char game_board[3][3]);

int main(){
  char game_board[3][3];
  CreateBoard(game_board);
  DisplayBoard(game_board);
}


/*
Creates an empty board for the TicTacToe game to be played on

@param: A 3x3 array of characters to be used for the TicTacToe game
@return: The array will be filled with dashes ('-') to indicate empty spaces.
*/
void CreateBoard(char game_board[3][3]){

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      game_board[i][j] = '-';
    }
  }

}


/*
Prints the board to the screen so players can see it

@param: The game board being used for the TicTacToe game
return: Prints the current state of the game board to the screen
*/
void DisplayBoard(char game_board[3][3]){

  std::cout << "\n";

  std::cout << " " << game_board[0][0] << " " << "|" << " " << game_board[0][1] << " " << "|" << " " << game_board[0][2] << " " << "\n";
	std::cout << "---|---|---" << "\n";
	std::cout << " " << game_board[1][0] << " " << "|" << " " << game_board[1][1] << " " << "|" << " " << game_board[1][2] << " " << "\n";
	std::cout << "---|---|---" << "\n";
	std::cout << " " << game_board[2][0] << " " << "|" << " " << game_board[2][1] << " " << "|" << " " << game_board[2][2] << " " << "\n";
}
