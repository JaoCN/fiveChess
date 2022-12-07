#include "chess.h"


int Chess::playinit(char *getname, int getplayflag){
    name = getname;
    playflag = getplayflag;
    playtime = 0;
    return 0;
}


int Chess::playchess(int x, int y, int **playboard){
    if (playboard[x][y] != -1)
    {
        return -1;
    }
    else{
        playboard[x][y] = playflag;
        chessarr[playtime][0] = x;
        chessarr[playtime][1] = y;
        playtime++;
    }
    
    return 0;
}