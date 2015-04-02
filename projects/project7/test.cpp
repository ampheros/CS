#include <iostream>
#include <fstream>
#include "triangle.h"

using namespace std;

int numTriangles = 4;

int main()
{
	triangle *tPtr = NULL;
	tPtr = new triangle [numTriangles];

	ifstream fin;
	fin.open("dimensions");

	triangle zero;
	cout << "zero: " << zero << endl;

	triangle basic(5,10);
	cout << "basic: " << basic << endl;

	if(zero == basic)
		cout << "zero and basic are the same" << endl;
	else
		cout << "zero and basic are different" << endl;

	cout << endl;
	zero = basic;
	cout << "zero after assignment: " << zero << endl;

	triangle basic2 = basic;
	cout << "basic2 using copy constructor: " << basic2 << endl;

	triangle sum;
	sum = zero + basic;
	cout << "sum = zero + basic: " << sum << endl;

	for(int i = 0; i < numTriangles; i++)
		fin >> tPtr[i];

	for(int i = 0; i < numTriangles; i++)
		cout << "triangle " << i+1 << ": " << tPtr[i] << endl;

	return 0;
}

