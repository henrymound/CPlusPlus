//Guess my number game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	//**Set up**
	cout << "----- Guess My Number! -----" << endl; //Welcomes the user

	int compGuess = 50;
	int numberToGuess;
	int guessAttempts = 0;
	int lowerBracket = 0;//Used to help improve computer's guesses
	int upperBracket = 100;
	int guessList[100];
	for(int counter = 0; counter < 100; counter++){//fills array with possible guesses (0-100) for search
		guessList[counter] = counter;
	}

	srand(static_cast<unsigned int>(time(0)));//Uses time to seed random number

	cout << "Enter a number between 1 and 100 for the computer to guess: ";//User picks a number for the computer to guess
	cin >> numberToGuess; 

	//**Game Loop**
	do{
		//*Get Player Input* - Generates computer's guess
		
		//*Update Game Internals*
		guessAttempts++;

		//*Update Display*
		//*Game Over?*
		int low = 1;
		int high = 100;
		int mid;
		while (low <= high){
			mid = low + (high-low)/2;
			cout << "I am going to guess the number is " << guessList[mid] << "." ; 
			if(guessList[mid] == numberToGuess){
				cout << "\nI guessed the secret number in " << guessAttempts << " tries!\n";
				compGuess = guessList[mid];
				break;
			}else if (guessList[mid] < numberToGuess){
				cout << "\nMy guess wass too low! I'll guess higher next time.\n";
				low = mid+1;
			}else{
				//*Shut Down*
				high = mid-1;
				cout << "\nMy guess was too high! I'll guess lower next time.\n";
			}
			guessAttempts++;
		}
	}while (compGuess != numberToGuess);

	system("pause");
	return 0;
}