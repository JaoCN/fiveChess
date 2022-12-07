class Chess{
	public:
        char* name;
        int chessarr[200][2];
        int playflag;
        int playtime;

        int playinit(char *getname, int getplayflag);
        int playchess(int x, int y, int **playboard);
};
