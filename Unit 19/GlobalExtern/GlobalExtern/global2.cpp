#include "global_extern.h"

void access_global(){
	cout << "In access_global() glob is " << glob << "\n\n";
}

void hide_global(){
	cout << "In hide_global glob is: " << glob << "\n\n";
}

void change_global(){
	glob = -10;
	cout << "In change global() glob is " << glob << "\n\n";
}