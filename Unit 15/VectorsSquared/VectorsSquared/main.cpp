#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<float> floatVector;

	//fills the first float vector with 25 randomly generated floats
	for (int i = 0; i < 25; i++)
		floatVector.push_back((float)(rand() % 100));

	//print out vector before squaring
	cout << "Vector Before Squaring\n---------------------" << endl;
	for (int i = 0; i < floatVector.size(); i++)
		cout << floatVector[i] << endl;
	cout << endl;

	//square all elements in vector
	for (int i = 0; i < floatVector.size(); i++)
		floatVector[i] *= floatVector[i];

	//print out vector after squaring
	cout << "Vector After Squaring\n---------------------" << endl;
	for (int i = 0; i < floatVector.size(); i++)
		cout << floatVector[i] << endl;
	cout << endl;

	system("pause");
}