
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	char* file_name;
	in.open(file_name);
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
	in.close();
	return 1;

}

void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		std::cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		std::cout << s;
	}
}


int main(void)
{
	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(baseHP1,baseHP2,wp1,wp2,ground);
	
	//write your code here
	int realHP[2], baseHP[2], wp[2], paladin[2];
	baseHP[1] = baseHP1; baseHP[2] = baseHP2;
	wp[1] = wp1; wp[2] = wp2;


	for (int i = 1; i <= 2; i++) {
		if (wp[i] == 0) {
			realHP[i] = (int)(baseHP[i] / 10);
		}
		else {
			realHP[i] = baseHP[i];
		}
		if (ground == baseHP[i]) {
			realHP[i] *= 1.1;
		}
		int count = 0;
		paladin[i] = 0;
		for (int a = 1; a <= baseHP[i]; a++) {
			if ((baseHP[i] % a) == 0) {
				count += 1;
			}
		}
		if (count == 2) {
			paladin[i] = 1;
		}
	}

	if (wp[1] == 3) {
		realHP[1] *= 2;
	}
	if (realHP[1] > 999) {
		realHP[1] = 999;
	}

	if (baseHP[1] == 999) {
		fOut = 1;
	}
	else if (baseHP[2] == 888) {
		fOut = 0;
	}
	else if ((paladin[1] == 1) && (paladin[2] == 0)) {
		fOut = 0.99;
	}
	else if ((paladin[1] == 0) && (paladin[2] == 1)) {
		fOut = 0.01;
	}
	else if ((paladin[1] == 1) && (paladin[2] == 1)) {
		if (baseHP[1] < baseHP[2]) {
			fOut = 0.01;
		}
		else if (baseHP[1] > baseHP[2]) {
			fOut = 0.99;
		}
		else fOut = 0.50;
	}
	else if (((realHP[1] < realHP[2]) && (wp[1] == 2)) || ((realHP[1] > realHP[2]) && (wp[2] == 2) && (wp[1] != 3))) {
		fOut = 0.50;
	}
	else fOut = ((float)realHP[1] - (float)realHP[2] + 999) / 2000;

	display(fOut);

	return 0;
}
