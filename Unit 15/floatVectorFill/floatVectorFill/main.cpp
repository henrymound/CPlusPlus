#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<float> floatVector;

	//fills the float vector with 25 randomly generated floats
	for (int i = 0; i < 25; i++)
		floatVector.push_back((float)((rand() % 100000) / (atan(1) * 4)) );
	
	//displays vector
	for (int i = 0; i < floatVector.size(); i++)
		cout << floatVector[i] << endl;

	system("pause");
}