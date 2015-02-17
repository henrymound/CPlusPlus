#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<float> floatVector, float1Vector, sumVector;

	//fills the first two float vectors with 25 randomly generated floats
	for (int i = 0; i < 25; i++)
		floatVector.push_back((float)((rand() % 100000) / (atan(1) * 4)));

	for (int i = 0; i < 25; i++)
		float1Vector.push_back((float)((rand() % 100000) / (atan(1) * 4)));

	//add the corresponding elements of each vector together
	for (int i = 0; i < 25; i++)
		sumVector.push_back(floatVector[i] + float1Vector[i]);

	//displays all three vectors
	cout << "Vector 1\tVector 2\tSum" << endl;
	cout << "---------------------------------------" << endl;

	for (int i = 0; i < sumVector.size(); i++){
		cout << floatVector[i] << "\t\t" << float1Vector[i] << "\t\t" << sumVector[i] << endl;
	}

	system("pause");
}