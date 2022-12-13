#include "chess.h"


int Chess::playinit(char getname[], int getplayflag, int num){
    // name = getname;
    strcpy(name, getname);
    playernum = num;
    playflag = getplayflag;
    playtime = 0;
    // printf("Init name : %s\n", name);
    // printf("%s player name point is %p\n", name, &name);
    return 0;
}


int Chess::playchess(int x, int y, int **playboard){
    if (playboard[x][y] != -1)
    {
        return -1;
    }
    else{
        playboard[x][y] = playstyle;
        chessarr[playtime][0] = x;
        chessarr[playtime][1] = y;
        playtime++;
    }
    
    return 0;
}

int Chess::update_style(int flag){
    playstyle = flag;
    return 0;
}

int Chess::playchess_infor(int x_and_y[2]){
    // printf("name : %s\n", name);
    // printf("%s player name point is : %p\n", name, &name);
    std::cout << "name : " << this->name << std::endl;
    int x, y;
    printf("player %s input x :", this->name);
    scanf("%d", &x);
    printf("player %s input y :", this->name);
    scanf("%d", &y);
    x_and_y[0] = y;
    x_and_y[1] = x;
    return 0;
}

