//: max_score.cpp
// Break a file into whitespace-separated words
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<int> scores;
	vector<int>::const_iterator iter;

	ifstream in("scores.txt");
	string line;

	while (getline(in, line))
		scores.push_back(std::stoi(line));

	unsigned int i = 0;
	int high = scores[i++];
	for (iter = scores.begin(); iter != scores.end(); ++iter){
		if (*iter > high){
			high = *iter;
		}
	}

	cout << "High score: " << high << endl;
	system("pause");
} ///:~