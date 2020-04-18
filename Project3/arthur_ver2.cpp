/*****Version 1.1***********/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(const char* filename, int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	ifstream in;
	in.open(filename);
	
	if (!in.good()) return 0;

	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;

	in.close();

	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;

	return 1;

}

// TODO: Your code goes here

void display(float fOut)
// display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		cout << s;
	}
}


int main(int argc, char** argv)
{
	if (argc < 2) return 1;

	const char* filename = argv[1];
	cout << filename << endl;

	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(filename, baseHP1, baseHP2, wp1, wp2, ground);
	
	// TODO: Your code goes here


	display(fOut);

	return 0;
}
