#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("story.txt");

	//The 'allContent' variable holds a string with all content from file concatinated
	string line, allContent; 

	while (getline(in, line))
		v.push_back(line);

	for (int i = 0; i < v.size(); i++)
		allContent += v[i] + "\n";

	cout << allContent;

	system("pause");
} 

