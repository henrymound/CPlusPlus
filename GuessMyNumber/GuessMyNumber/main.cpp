//Guess my number game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	//**Set up**
	srand(static_cast<unsigned int>(time(0)));//Uses time to seed random number
	int randomNumber = (rand() % 100) + 1;//Generates random number between 1 and 100
	int guessAttempts = 0;
	int guess;

	cout << "----- Guess My Number! -----" << endl; //Welcomes the user

	//**Game Loop**
	do{
		//*Get Player Input*
		cout << "Enter a guess between 1 and 100: " ; 
		cin >> guess;//reads and records the guess
		
		//*Update Game Internals*
		guessAttempts++;

		//*Update Display*
		//*Game Over?*
		if(guess > randomNumber){
			cout << "\nYou're guess wass too high!\n";
		}else if (guess < randomNumber){
			cout << "\nYou're guess wass too low!\n";
		}else if (guess == randomNumber){
			//*Shut Down*
			cout << "\nYou guessed the secret number in " << guessAttempts << " tries. Good Job!\n";
		}
	}while (guess != randomNumber);

	system("pause");
	return 0;
}