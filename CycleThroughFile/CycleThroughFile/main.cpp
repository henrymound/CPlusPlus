#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("song.txt");
	string line;
	while (getline(in, line))
		v.push_back(line);

	cout << "Press Enter to Display Each Line\n----------------------------------\n" << endl;
	for (int i = 0; i < v.size(); i++){
		cout << i << ": " << v[i] << endl;
		getchar(); //Wait for the user to press enter to continue
	}

	system("pause");
} 

