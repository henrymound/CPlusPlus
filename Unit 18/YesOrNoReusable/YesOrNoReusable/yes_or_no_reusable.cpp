// Yes or No
// Demonstrates return values and parameters

#include "yes_or_no_r.h"

char askYesNo1()
{
	char response1;
	do
	{
		cout << "Please enter 'y' or 'n': ";
		cin >> response1;
	} while (response1 != 'y' && response1 != 'n');

	return response1;
}

char askYesNo2(string question)
{
	char response2;
	do
	{
		cout << question << " (y/n): ";
		cin >> response2;
	} while (response2 != 'y' && response2 != 'n');

	return response2;
}


