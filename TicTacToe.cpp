/*
Travis Torline and Chris McCarroll-Gilbert

This program creates a simple two-player game of Tic-Tac-Toe
Users are asked to input the desired location of their marker
A winner is determined by who gets three in a row
If the board is filled up with no three in a row, the game is a tie.

No arguments are required to run this program. Type make and then ./TicTacToe
*/

#include <iostream>
#include <string>
#include <vector>

//Creates an empty board for the TicTacToe game to be played on
void CreateBoard(char game_board[3][3]);

//Prints the board to the screen so the players can see it
void DisplayBoard(char game_board[3][3]);

//Gets the position that a Player would like to put their marker
std::string GetPlayerChoice();

//Updates the board with a marker in the position requested by the player
void PlaceMarker(char game_board[3][3], std::string location, char marker);

//Checks to see if there are three in a row anywhere on the board
bool CheckWin(char game_board[3][3]);

int main(){

  //The game loop begins by creating an empty board to play on
  char game_board[3][3];
  CreateBoard(game_board);

  bool continue_game = false;
  char marker = 'X';
  std::string player_choice;
  int counter = 0;

  //If continue_game is true, a winner has been found. If the counter is equalt o 9, it must be a tie
  while(!continue_game && counter < 9){

    //Each iteration displays the board, askes the player to mark a spot, updates the board, and then checks for a winner
    DisplayBoard(game_board);
    player_choice = GetPlayerChoice();
    PlaceMarker(game_board, player_choice, marker);

    if(marker == 'X'){
      marker = 'O';
    }else{
      marker = 'X';
    }

    continue_game = (CheckWin(game_board));
    counter++;
  }

  DisplayBoard(game_board);

  if(counter == 9){
    std::cout<<"It's a tie!"<<"\n";
  }else{
    std::cout<<"Game over! We have a winner!"<<"\n";
  }

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

/*
Gets the position that a Player would like to position their marker

@param: None
@return: Returns a string with the poisiton input from the player
*/
std::string GetPlayerChoice(){

	std::string string_choice;
	std::cout << "Enter a position between 1-9 to place your marker: " << std::endl;
	std::cin >> string_choice;

	return string_choice;
}

/*
Gets the position that a Player would like to position their marker

@param: The game board being used for the game, a string specifiying a location, and a character marker to place in that location
@return: Updates the passed postion with he passed marker
*/
void PlaceMarker(char game_board[3][3], std::string location, char marker){

  if(location == "1"){
    game_board[0][0] = marker;
  }else if(location == "2"){
    game_board[0][1] = marker;
  }else if(location == "3"){
    game_board[0][2] = marker;
  }else if(location == "4"){
    game_board[1][0] = marker;
  }else if(location == "5"){
    game_board[1][1] = marker;
  }else if(location == "6"){
    game_board[1][2] = marker;
  }else if(location == "7"){
    game_board[2][0] = marker;
  }else if(location == "8"){
    game_board[2][1] = marker;
  }else{
    game_board[2][2] = marker;
  }

}

/*
Gets the position that a Player would like to position their marker

@param: The game board being used for the game
@return: Returns true if three in a row is found anywhere on the board, and false if there are no instances of three in a row
*/
bool CheckWin(char game_board[3][3]){

  //Must ensure that the three in a row is NOT the "empty" character, or '-'. These are just spaces without any markers placed yet.
  if((game_board[0][0] == game_board[0][1]) && (game_board[0][0] == game_board[0][2]) && (game_board[0][0] != '-')){
    return true;
  }else if((game_board[1][0] == game_board[1][1]) && (game_board[1][0] == game_board[1][2]) && (game_board[1][0] != '-')){
    return true;
  }else if((game_board[2][0] == game_board[2][1]) && (game_board[2][0] == game_board[2][2]) && (game_board[2][0] != '-')){
    return true;
  }else if((game_board[0][0] == game_board[1][0]) && (game_board[0][0] == game_board[2][0]) && (game_board[0][0] != '-')){
    return true;
  }else if((game_board[0][1] == game_board[1][1]) && (game_board[0][1] == game_board[2][1]) && (game_board[0][1] != '-')){
    return true;
  }else if((game_board[0][2] == game_board[1][2]) && (game_board[0][2] == game_board[2][2]) && (game_board[0][2] != '-')){
    return true;
  }else if((game_board[0][0] == game_board[1][1]) && (game_board[0][0] == game_board[2][2]) && (game_board[0][0] != '-')){
    return true;
  }else if((game_board[0][2] == game_board[1][1]) && (game_board[0][2] == game_board[2][0]) && (game_board[0][2] != '-')){
    return true;
  }else{
    return false;
  }

}
