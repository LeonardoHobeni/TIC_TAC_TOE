#ifndef TTT_H
#define TTT_H
class TTT
{
    public:
        void playGame(int&, int&);
        //Precondition:
            //function allows user to play the game
        bool Winner();
        //Precondition:
            //function checks if there's a winner and returns the appropriate boolean value
        bool EmptySpace(int, int);
        //Precondition:
            //function checks if for empty spaces and returns the approppriate boolean value
        bool NoSpace();
        //Precondition:
            //function checks if there's no space and returns the appropriate boolean value
        bool PlayerTurn(int, int);
        //Precondition:
            //function checks for which player is suppose to play a turn and returns the appropriate boolean value
        bool GameOn();
        //Precondition:
            //function checks if the game is still on and return the appropriate boolean value
        char WhoWon();
        //Precondition:
            //function checks for who won the game and return the appropriate character(symbol)
        void Initialize();
        //Precondition:
            //function initializes the board
        void printBoard();
        //Precondition:
            //function prints the board
        void BoardGuide();
        //Precondition:
            //function displays the guide on how to play the game
        void PlaceSymbol(char);
        //Precondition:
            //function place the correct symbol in the place of choice
        void PlayAgain();
        //Precondition:
            //function prompts the user and asks if they want to play again
        bool Play(char);
        //Precondition:
            //function determines if the players want to play again and return the appropriate boolean value
        void setBoard();
        //Precondition:
            //function creates the dynamic two dimensional array
    private:
        char **Board;//pointer to pointer member variable
};

#endif
