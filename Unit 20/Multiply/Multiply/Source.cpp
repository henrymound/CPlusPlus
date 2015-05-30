#include <iostream>
#include <string>

using namespace std;

int multiply(int multiplier, int number);
string multiply(int multiplier, string text);

int main()
{
	string numberOrText;
	int number;
	int multiplier;

	cout << "Enter a number or word: ";
	cin >> numberOrText;

	cout << "Enter a number to multiply by: ";
	cin >> multiplier;

	number = atoi(numberOrText.c_str());
	if (number != NULL)
		cout << multiply(multiplier, number);
	else
		cout << multiply(multiplier, numberOrText);

	system("pause");
	return 0;
}

int multiply(int multiplier, int number)
{
	return (multiplier * number); 
}

string multiply(int multiplier, string text)
{
	string toReturn = "";
	for (int i = 0; i < multiplier; i++)
		toReturn += text;
	return toReturn;
}

