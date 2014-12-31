#include <iostream>
#include <string>
using namespace std;

int main(){
	//declare variables
	string username;
	int num1, num2, num3;
	double average;

	//prompts for username
	cout << "Enter Username: ";
	cin >> username;
	
	//prompts for three numbers
	cout << "Enter first int: ";
	cin >> num1;
	cout << "Enter second int: ";
	cin >> num2;
	cout << "Enter third int: ";
	cin >> num3;
	average = (num1 + num2 + num3)/3.0;
	cout << "\n\nEntered username: \"" << username << "\".\nThe average of " << num1 << ", " << num2 << ", and " << num3 << " is " << average << ".\n\n";

	system("pause");
	return 0;
}