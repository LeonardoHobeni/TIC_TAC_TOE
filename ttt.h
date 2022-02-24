#ifndef TTT_H
#define TTT_H
class TTT
{
    public:
        void playGame(int&, int&);
        bool Winner();
        bool EmptySpace(int, int);
        bool NoSpace();
        bool PlayerTurn(int, int);
        bool GameOn();
        char WhoWon();
        void Initialize();
        void printBoard();
        void BoardGuide();
        void PlaceSymbol(char);
        void PlayAgain();
        bool Play(char);

    private:
        char **Board;
};

#endif
