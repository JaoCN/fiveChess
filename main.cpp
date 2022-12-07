#include <iostream>
#include "chess.h"

using namespace std;
int **checkerboard;
int checkboardsize;

int Initcheckerboard();
int Delcheckerboard();
int Printcheckerboard();

int main(){
	checkboardsize = 4;
	Initcheckerboard();
	Printcheckerboard();
	Delcheckerboard();
	return 0;
}


int Initcheckerboard(){
	checkerboard = new int*[checkboardsize];
	for (int i = 0; i < checkboardsize; i++){
		checkerboard[i] = new int[checkboardsize];
		for (int j = 0; j < checkboardsize; j++){
			checkerboard[i][j] = -1;
		}
	}
	return 0;
}

int Delcheckerboard(){
	for (int i = 0; i < checkboardsize; i++)
		delete[] checkerboard[i];
	delete[] checkerboard;
	return 0;
}

int Printcheckerboard(){
	string char_underline("---");
	string char_equal("|");
	string line("----");
	string separate = char_underline + char_equal;
	line.append(char_equal);
	for (auto iter = 0; iter < checkboardsize - 2; iter++) line.append(separate);
	line.append("----");
	for (auto row = 0; row < checkboardsize; row++){
		for (auto col = 0; col < checkboardsize; col++){
			if (col == 0) cout << " ";
			//cout << checkerboard[row][col];
			cout << (checkerboard[row][col] == 0 ? " O "
												: checkerboard[row][col] == 1 ? " X "
																			  : " F ");
			if (col != (checkboardsize - 1)) cout << "|";
		}
		if (row != (checkboardsize - 1)) cout << endl << line << endl;
	}
	cout << endl;
	return 0;
}

