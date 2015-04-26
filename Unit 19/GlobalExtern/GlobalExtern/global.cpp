#include <iostream>
#include "global_extern.h"

int glob = 10;

int main(){
	cout << "In main() glob is: " << glob << "\n\n";
	access_global();

	hide_global();
	cout << "In main() glob is: " << glob << "\n\n";

	change_global();
	cout << "In main() glob is: " << glob << "\n\n";

	system("pause");

}