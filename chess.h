#include <stdio.h>
#include <iostream>
#include <string.h>

class Chess
{
public:
        char name[10];
        int playernum;
        int chessarr[200][2];
        int playflag;   // order : 0/first , 1/second
        int playtime;
        int playstyle;

        int playinit(char getname[], int getplayflag, int num);
        int playchess(int x, int y, int **playboard);
        int playchess_infor(int x_and_y[2]);
        int update_style(int flag);
};
