#include <conio.h>
#include <iostream>
#include <Windows.h>

// height and width of the boundary
const int width = 80;
const int height = 20;

// Snake head coordinates of snake (x-axis, y-axis)
int x, y;
// Food coordinates
int fruitCordX, fruitCordY;
// Variable to store the score of the player
int playerScore;
// Array to store the coordinates of snake tail (x-axis, y-axis)
int snakeTailX[100], snakeTailY[100];
// variable to store the length of the snake's tail
int snakeTailLen;
// for storing snake's moving snakeDirection
enum snakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
// snakeDirection variable
snakeDirection sDir;
// Boolean variable for checking game is over or not
bool isGameOver;

void GameInit()
{
	isGameOver = false;
	sDir = STOP;
	x = width / 2;
	y = height / 2;
	fruitCordX = rand() % width;
	fruitCordY = rand() % height;
	playerScore = 0;
}

// Function for creating the game board & rendering
void GameRender(string playerName)
{
	system('cls'); // Clear the console

	// Creating top walls with '-'
	for (int i = 0; i < width + 2; i++)
		cout << '-';
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j <= width; j++) {
			// Creating side wall with '|'
			if (j == 0 || j == width)
				cout << '|';
			// Creating snake's head with 'O'
			if (i == y && j == x)
				cout << 'O';
			// Creating the snake's food with '#'
			else if (i == fruitCordY && j == fruitCordX)
				cout << '#';
			// Creating snake's head with 'O'
			else {
				bool prTail = false;
				for (int k = 0; k < snakeTailLen; k++) {
					if (snakeTailX[k] == j
						&& snakeTailY[k] == i) {
						cout << 'O';
						prTail = true;
					}
				}
			}
		}
	}

}