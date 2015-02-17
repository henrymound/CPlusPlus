#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> words;
	vector<string> lineVector;
	string line;
	ifstream lineIn("poem.txt");
	ifstream in("poem.txt");
	
	string word;
	string wordToSearch = "good";//holds the word to search for

	int numberOfWords = 0; //variable to hold the number of words in the file
	int numberFound = 0; //variable to hold the number of instances of the word to search
	
	//Displays File
	cout << "----------- FILE CONTENTS -----------\n" << endl;
	while (getline(lineIn, line))
		lineVector.push_back(line); // Add the line to the end
	for (int i = 0; i < lineVector.size(); i++)	// Add line numbers:
		cout << i << ": " << lineVector[i] << endl;
	cout << endl;

	//Counts Words
	while (in >> word)
		words.push_back(word);

	for (int i = 0; i < words.size(); i++){
		if (words[i] == wordToSearch)
			numberFound++;
		numberOfWords++;
	}

	cout << numberOfWords << " words in file." << endl;
	cout << numberFound << " instances of the word \"" << wordToSearch << "\".\n\n";

	system("pause");
}