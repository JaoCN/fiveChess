#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chess.h"

using namespace std;
int **checkerboard;
int checkboardsize;

Chess p1, p2;

// 棋盘初始化、打印以及释放
int Initcheckerboard();
int Delcheckerboard();
int Printcheckerboard();

// 开始
int start();

int main(){
	checkboardsize = 4;
	Initcheckerboard();
	// Printcheckerboard();
	start();
	Delcheckerboard();
	return 0;
}


int startinformation(){
	// cout << "# Welcome to chess game" << endl;
	// cout << "# Describe: This is a game for two players who take turns marking the spaces in a board with X or O" << endl;
	// cout << "# The player who succeeds in placing three or five of their marks in a horizontal,vertical or diagonal" << endl;
	// cout << "# row is the winner." << endl;
	// cout << "# If you are ready, please press the key \"Y\" to start the game and key \"Q\" to quit the game : " << endl;
	string start_information = 
		"# Welcome to chess game\n"
		"# Describe: This is a game for two players who take turns marking the spaces in a board with X or O\n"
		"# The player who succeeds in placing three or five of their marks in a horizontal,vertical or diagonal\n"
		"# row is the winner.\n"
		"# If you are ready, please press the key \"Y\" to start the game and key \"Q\" to quit the game : ";

	cout << start_information << endl;
	do
	{
		// cout << "\r\b\r";
		cout << "\r\033[1A\033[K";
		cout << "# If you are ready, please press the key \"Y\" to start the game and key \"Q\" to quit the game : ";

		// char startvalue;
		string startvalue;
		// cin >> startvalue;
		getline(cin, startvalue);
		if (startvalue[0] == 'Y' || startvalue[0] == 'y')
		{
			cout << "Start!" << endl;
			return 0;
		}
		else if (startvalue[0] == 'Q' || startvalue[0] == 'q')
		{
			cout << "# EXIT! ";
			return -1;
		}
	} while (1);

	return 0;
}

int playinformation(){
	char name1[20], name2[20];
	int num1, num2;


	srand(time(0));
	cout << "# Please input player1 name : ";
	cin >> name1;
	cout << "# Please input player2 name : ";
	cin >> name2;
	num1 = rand() % 100;
	num2 = rand() % 100;
	cout << "compare num " << num1 << num2 << endl;
	if(num1 >= num2){
		cout << "# player " << name1 << " first" << endl;
		p1.playinit(name1, 0);
		p2.playinit(name2, 1);
	}
	else{
		cout << "# player " << name2 << " first" << endl;
		p1.playinit(name1, 1);
		p2.playinit(name2, 0);
	}

	cout << "player1 :" << p1.name << " order : " << p1.playflag << endl;
	cout << "player2 :" << p2.name << " order : " << p2.playflag << endl;

	return 0;
}

int play(){
	int order;
	do{
		if(p1.playflag == 0){
			
		}
		else if(p2.playflag == 0){

		}
		else{
			return -1;
		}

	}while(judge_end());
	return 0;
}

int start(){
	if(startinformation() == 0){
		playinformation();
		play();
	}
	else
	{
		cout << "The game is end by user, now exit the program" << endl;
	}
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

