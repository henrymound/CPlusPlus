
#include "yes_or_no_r.h"

int main()
{
	char answer1 = askYesNo1();
	cout << "Thanks for answering: " << answer1 << "\n\n";

	char answer2 = askYesNo2("Do you wish to save your game?");
	cout << "Thanks for answering: " << answer2 << "\n";

	system("pause");
	return 0;
}

