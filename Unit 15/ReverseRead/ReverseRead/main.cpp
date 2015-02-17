#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("story.txt");
	string line;
	while (getline(in, line))
		v.push_back(line); 
	
	//Prints lines in reverse order by looping through from max to min
	for (int i = v.size(); i > 0; i--)
		cout << i-1 << ": " << v[i-1] << endl;

	system("pause");
}

