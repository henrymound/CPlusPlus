//Guess my number game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	//**Set up**
	cout << "----- Guess My Number! -----" << endl; //Welcomes the user

	int numberToGuess;
	int guess;
	int guessAttempts = 0;
	int lowerBracket = 0;//Used to help improve computer's guesses
	int upperBracket = 100;

	srand(static_cast<unsigned int>(time(0)));//Uses time to seed random number

	cout << "Enter a number between 1 and 100 for the computer to guess: ";//User picks a number for the computer to guess
	cin >> numberToGuess; 

	//**Game Loop**
	do{
		//*Get Player Input* - Generates computer's guess
		guess = (rand() % (upperBracket - lowerBracket)) + lowerBracket;
		cout << "I am going to guess the number is " << guess << "." ; 
		
		//*Update Game Internals*
		guessAttempts++;

		//*Update Display*
		//*Game Over?*
		if(guess > numberToGuess){
			cout << "\nMy guess was too high! I'll guess lower next time.\n";
			upperBracket = guess;
		}else if (guess < numberToGuess){
			cout << "\nMy guess wass too low! I'll guess higher next time.\n";
			lowerBracket = guess;
		}else if (guess == numberToGuess){
			//*Shut Down*
			cout << "\I guessed the secret number in " << guessAttempts << " tries!\n";
		}
	}while (guess != numberToGuess);

	system("pause");
	return 0;
}