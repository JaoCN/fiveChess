#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chess.h"

using namespace std;
int **checkerboard;
int checkboardsize;
const char *p1_style, *p2_style, *default_style;
const char *stylearr[] = {" X ", " O ", "   "};
Chess p1, p2;



// 棋盘初始化、打印以及释放
int Initcheckerboard();
int Delcheckerboard();
int Printcheckerboard();

// 开始
int start();

int main(){
	checkboardsize = 3;
	p1_style = stylearr[0];
	p2_style = stylearr[1];
	default_style = stylearr[2];
	Initcheckerboard();
	Printcheckerboard();
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
	int first_player_num = 0;
	int choose_style_flag = 0;


	srand(time(0));
	cout << "# Please input player1 name : ";
	cin >> name1;
	cout << "# Please input player2 name : ";
	cin >> name2;
	num1 = rand() % 100;
	num2 = rand() % 100;
	cout << "compare num " << num1 << num2 << endl;
	if(num1 >= num2){
		p1.playinit(name1, 0, 1);
		p2.playinit(name2, 1, 2);
		cout << "# player " << p1.name << " first" << endl;
		first_player_num = 1;
	}
	else{
		p1.playinit(name1, 1, 1);
		p2.playinit(name2, 0, 2);
		cout << "# player " << p2.name << " first" << endl;
		first_player_num = 2;
	}

	cout << "player1 :" << p1.name << " order : " << p1.playflag << endl;
	cout << "player2 :" << p2.name << " order : " << p2.playflag << endl;

	do{
		printf("Please player %d choose chess style [ X ]/[ O ] ([0]/[1]) :", first_player_num);
		scanf("%d", &choose_style_flag);
		if((p1.playflag == 0 && choose_style_flag == 0) || (p2.playflag == 0 && choose_style_flag == 1)){
			p1.update_style(0);
			p2.update_style(1);
			printf("Player %d choose chess style %s\n", p1.playernum, stylearr[p1.playstyle]);
			printf("Player %d choose chess style %s\n", p2.playernum, stylearr[p2.playstyle]);
			break;
		}else if((p1.playflag == 0 && choose_style_flag == 1) || (p2.playflag == 0 && choose_style_flag == 0)){
			p1.update_style(1);
			p2.update_style(0);
			printf("Player %d choose chess style %s\n", p1.playernum, stylearr[p1.playstyle]);
			printf("Player %d choose chess style %s\n", p2.playernum, stylearr[p2.playstyle]);
			break;
		}
		printf("input error! Please inpu again\n");
	}while(1);

	return 0;
}

int judge_end(int x, int y){
	char horizontal[checkboardsize];
	char vertical[checkboardsize];

	int rightsize, leftsize;
	// 获取斜对角数组的长度
	if (x != y)// 非斜对角
	{
		rightsize = checkboardsize - ((x > y) ? (x - y) : (y - x));
		leftsize = rightsize;
	}else if (x == y)	//右下对角
	{
		rightsize = checkboardsize;
		int mid = (checkboardsize - 1) / 2;
		int size = (x >= mid) ? checkboardsize - 1 - x : x;
		leftsize = (2 * size) + 1;
		
	}else if ((x + y + 1) == checkboardsize)	//左下对角
	{
		leftsize = checkboardsize;
		int mid = (checkboardsize - 1) / 2;
		int size = (x >= mid) ? checkboardsize - 1 - x : x;
		rightsize = (2 * size) + 1;
	}
	
	
	char right[rightsize];	// 左斜下
	char left[leftsize];	// 右斜上
	

	for (size_t i = 0; i < checkboardsize; i++)
	{
		horizontal[i] = checkerboard[i][y];
		vertical[i] = checkerboard[x][i];


	}
	return 0;
	
	// int chess_jug_flag;
	// if(checkerboard[x][y] == 0){
	// 	chess_jug_flag = 0;
	// }else if (checkerboard[x][y] == 1)
	// {
	// 	chess_jug_flag = 1;
	// }

	// // judge
	// if(checkboardsize == 3){
	// 	if()
	// }else if(chess_jug_flag == 5){

	// }
}

int play()
{
	int order = -1;
	int chess[2];
	if (p1.playflag == 0)
	{
		order = 0;
	}
	if (p2.playflag == 0)
	{
		order = 1;
	}

	do
	{
		if(order == 1) goto p2_chess;
	p1_chess:
		p1.playchess_infor(chess);
		if (checkerboard[chess[0]][chess[1]] == -1)
		{
			p1.playchess(chess[0], chess[1], checkerboard);
		}
		else
		{
			printf("the position had a chess, please input again!\n");
			goto p1_chess;
		}
		if(order == 1) goto end;
	p2_chess:
		p2.playchess_infor(chess);
		if (checkerboard[chess[0]][chess[1]] == -1)
		{
			p2.playchess(chess[0], chess[1], checkerboard);
		}
		else
		{
			printf("the position had a chess, please input again!\n");
			goto p2_chess;
		}
		if(order == 1) goto p1_chess;
	end:
		Printcheckerboard();

	} while (1);

	// order = 0;
	// do
	// {
	// 	if (p1.playflag == 0)
	// 	{
	// 		// if(order == 1) goto p2_chess1;
	// 	p1_chess1:
	// 		p1.playchess_infor(chess);
	// 		if (checkerboard[chess[0]][chess[1]] == -1)
	// 		{
	// 			p1.playchess(chess[0], chess[1], checkerboard);
	// 		}
	// 		else
	// 		{
	// 			printf("the position had a chess, please input again!\n");
	// 			goto p1_chess1;
	// 		}
	// 		// if(order == 1) goto end1;
	// 	p2_chess1:
	// 		p2.playchess_infor(chess);
	// 		if (checkerboard[chess[0]][chess[1]] == -1)
	// 		{
	// 			p2.playchess(chess[0], chess[1], checkerboard);
	// 		}
	// 		else
	// 		{
	// 			printf("the position had a chess, please input again!\n");
	// 			goto p2_chess1;
	// 		}
	// 		// if(order == 1) goto p1_chess1;
	// 	end1:
	// 		Printcheckerboard();
	// 		// if(order == 0) order = 1;
	// 		// else order = 0;
	// 	}
	// 	else if (p2.playflag == 0)
	// 	{
	// 		// if(order == 1) goto p1_chess2;
	// 	p2_chess2:
	// 		p2.playchess_infor(chess);
	// 		if (checkerboard[chess[0]][chess[1]] == -1)
	// 		{
	// 			p2.playchess(chess[0], chess[1], checkerboard);
	// 		}
	// 		else
	// 		{
	// 			printf("the position had a chess, please input again!\n");
	// 			goto p2_chess2;
	// 		}
	// 		// if(order == 1) goto end2;
	// 	p1_chess2:
	// 		p1.playchess_infor(chess);
	// 		if (checkerboard[chess[0]][chess[1]] == -1)
	// 		{
	// 			p1.playchess(chess[0], chess[1], checkerboard);
	// 		}
	// 		else
	// 		{
	// 			printf("the position had a chess, please input again!\n");
	// 			goto p1_chess2;
	// 		}
	// 		// if(order == 1) goto p2_chess2;
	// 	end2:
	// 		Printcheckerboard();
	// 		// if(order == 0) order = 1;
	// 		// else order = 0;
	// 	}
	// 	else
	// 	{
	// 		return -1;
	// 	}

	// 	// }while(judge_end());
	// } while (1);
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
			
			cout << (checkerboard[row][col] == 0 ? p1_style
												 : checkerboard[row][col] == 1 ? p2_style
																			   : default_style);
			if (col != (checkboardsize - 1)) cout << "|";
		}
		if (row != (checkboardsize - 1)) cout << endl << line << endl;
	}
	cout << endl;
	return 0;
}

