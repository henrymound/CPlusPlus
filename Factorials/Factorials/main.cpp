#include <iostream>

using namespace std;

int main(){

	short number;
	cout << "Enter Number: ";
	cin >> number;

	if(number >= 0){
		
		cout << "\nThe factorial of " << number << " is ";
		unsigned long long accumulator = 1;
		
		if (number > 10){
			for(; number > 0; accumulator *= number--);
		}else{
			switch(number){
			case 0:
				accumulator = 1;
				break;
			case 1:
				accumulator = 1;
				break;
			case 2:
				accumulator = 2;
				break;
			case 3:
				accumulator = 6;
				break;
			case 4:
				accumulator = 24;
				break;
			case 5:
				accumulator = 120;
				break;
			case 6:
				accumulator = 720;
				break;
			case 7:
				accumulator = 5040;
				break;
			case 8:
				accumulator = 40320;
				break;
			case 9:
				accumulator = 362880;
				break;
			case 10:
				accumulator = 3628800;
				break;
			}
		}
		
		cout << accumulator << ".\n"; 

	}else{
		cout << "\nThe factorial of " << number <<
			" is undefined.\nIt is impossible to find the factorial of a negative number.\n";
	}

	system("pause");
	return 0;
}