#include <iostream>
#include "ttt.h"

const int Row = 3, Col = 3;
using namespace std;

void TTT::PlayAgain()
{
    char play = 'Y';
    int Player1, Player2;
    while(Play(play))
    {
        //Initializing array:
        Initialize();

        //Printing guide:
        BoardGuide();

        //Game plays:
        playGame(Player1, Player2);

        cout << endl;
        cout << "To play again insert Y/y or stop:";
        cin >> play;
        cout << endl;
    }
    cout << "Player 1 point(s): " << Player1 << endl;
    cout << "Player 2 point(s): " << Player2 << endl;
    cout << "GAME OVER!!!" << endl;
}

void TTT::Initialize()
{
    //Initializing c-string
    for(int i = 0; i < Row; i++)
        for(int j = 0; j < Col; j++)
            Board[i][j] = ' ';
}

void TTT::printBoard()
{
    //prints the players' board:
    cout << endl;
    for(int i = 0; i < Row; i++)
        for(int j = 0; j < Col; j++)
        {
            cout << "|" << Board[i][j];
            if(j == 2 && i != 2)
            {
                cout << "|" << endl;
                cout << "-------"<< endl;
            }
            if(j == 2 && i == 2)
                cout << "|" << endl << endl;


        }
}

void TTT::BoardGuide()
{
    //Displaying guide on how to play:
    cout << "To place a marker in desired cell insert the" << endl;
    cout << "dimensions of the cell e.g: for 0;2,"
         << " you enter 0 and 2." << endl;

    cout << "_____________" << endl;
    cout << "|0;0|" << "0;1|" << "0;2|" << endl;
    cout << "-------------" << endl;
    cout << "|1;0|" << "1;1|" << "1;2|" << endl;
    cout << "-------------" << endl;
    cout << "|2;0|" << "2;1|" << "2;2|" << endl;
    cout << "-------------" << endl;

}

void TTT::playGame(int& Player1, int& Player2)
{
    char P1 = 'X', P2 = 'O';

    int P1T = 0, P2T = 0;

    static int P1P = 0, P2P = 0;

    printBoard();

    while(GameOn())
    {
        //Checking who's turn is it:
        if(PlayerTurn(P1T,P2T))
        {
            PlaceSymbol(P1);
            P1T++;//counts player turns
        }
        else
        {
            PlaceSymbol(P2);
            P2T++;//counts player turns
        }
        printBoard();//prints updated board
    }

    //Checking if it's a tie or not
    if(Winner()){
        if(WhoWon() == 'X')//finding the player that won the game
        {
            P1P++;
            cout << "Player 1 won the game" << endl;
            cout << "Won by " << P1T << " plays" << endl;
            cout << "Has " << P1P << " point(s)." << endl;
            Player1 = P1P;
        }
        else
        {
            P2P++;
            cout << "Player 2 won the game" << endl;
            cout << "Won by " << P2T << " plays" << endl;
            cout << "Has " << P2P << " point(s)." << endl;
            Player2 = P2P;
        }
    }


    if(NoSpace() && !Winner())
        cout << "It's a tie." << endl;


}

bool TTT::Winner()
{
    //Player 1:
    //checking rows:
    for(int i = 0; i < Row; i++)
        for(int j = 1; j <= 1; j++)
            if((Board[i][Col-(j+2)] == 'X')&&(Board[i][Col-(j+1)] == 'X')&&
               (Board[i][Col-j] == 'X'))
                return true;

    //checking columns:
    for(int j = 0; j < Col; j++)
        for(int i = 1; i <= 1; i++)
            if((Board[Row-(i+2)][j] == 'X')&&(Board[Row-(i+1)][j] == 'X')&&
               (Board[Row-i][j] == 'X'))
               return true;

    //checking diagonals:
    //main diagonal:
    for(int i = 0; i < 1; i++)
        if((Board[i][i] == 'X')&&(Board[i+1][i+1] == 'X')&&
           (Board[i+2][i+2] == 'X'))
            return true;

    //Other diagonal:
    for(int j = 0; j < 1; j++)
        if((Board[j][2] == 'X')&&(Board[j+1][2-(j+1)] == 'X')&&
           (Board[j+2][2-(j+2)] == 'X'))
            return true;

    //Player 2:
    //checking rows:
    for(int i = 0; i < Row; i++)
        for(int j = 1; j <= 1; j++)
            if((Board[i][Col-(j+2)] == 'O')&&(Board[i][Col-(j+1)] == 'O')&&
               (Board[i][Col-j] == 'O'))
                return true;

    //checking columns:
    for(int j = 0; j < Col; j++)
        for(int i = 1; i <= 1; i++)
            if((Board[Row-(i+2)][j] == 'O')&&(Board[Row-(i+1)][j] == 'O')&&
               (Board[Row-i][j] == 'O'))
                return true;

    //checking diagonals:
    //main diagonal:
    for(int i = 0; i < 1; i++)
        if((Board[i][i] == 'O')&&(Board[i+1][i+1] == 'O')&&
           (Board[i+2][i+2] == 'O'))
            return true;

    //Other diagonal:
    for(int j = 0; j < 1; j++)
        if((Board[j][2] == 'O')&&(Board[j+1][2-(j+1)] == 'O')&&
           (Board[j+2][2-(j+2)] == 'O'))
            return true;
    return false;
}

bool TTT::NoSpace()
{
    //Checking if spaces exist in the board/table
    int nospace = 0;
    for(int i = 0; i < Row; i++)
        for(int j = 0; j < Col; j++)
            if(Board[i][j] == ' ')
                ++nospace;//counting spaces
    if(nospace > 0)
        return false;
    return true;
}

void TTT::PlaceSymbol(char Symbol)
{
    int row, col;
    //Selecting player:
    if(Symbol == 'X')
        cout << "Player 1 turn:" << endl;
    else
        cout << "Player 2 turn:" << endl;

    cout << "Enter the dimensions of the cell: ";
    cin >> row >> col;
    cout << endl << endl;

    //Checking if cell is empty or not:
    while(!EmptySpace(row, col))
    {
        cout << "The cell is not empty choose an empty cell." << endl;
        cout << "Enter the dimensions of the cell: ";
        cin >> row >> col;
        cout << endl << endl;
    }
    Board[row][col] = Symbol;

}

bool TTT::PlayerTurn(int P1, int P2)
{
    //Determining player turn:
    if(P1 <= P2)
        return true;
    return false;
}

bool TTT::GameOn()
{
    //Checking if game is on:
    if(!Winner() && !NoSpace())
        return true;
    return false;
}

bool TTT::EmptySpace(int row, int col)
{
    if(Board[row][col] != ' ')
        return false;
    return true;
}

char TTT::WhoWon()
{
    //checking rows:
    for(int i = 0; i < Row; i++)
        for(int j = 0; j <1; j++)
            if((Board[i][j] == 'X')&&(Board[i][j+1] == 'X')&&
               (Board[i][j+2] == 'X'))
                return 'X';

    //checking columns:
    for(int j = 0; j < Col; j++)
        for(int i = 0; i < 1; i++)
            if((Board[i][j] == 'X')&&(Board[i+1][j] == 'X')&&
               (Board[i+2][j] == 'X'))
                return 'X';

    //checking diagonals:
    for(int i = 0; i < 1; i++)
        if((Board[i][i] == 'X')&&(Board[i+1][i+1] == 'X')&&
           (Board[i+2][i+2] == 'X'))
            return 'X';

    for(int j = 0; j < 1; j++)
        if((Board[j][2] == 'O')&&(Board[j+1][2-(j+1)] == 'O')&&
           (Board[j+2][2-(j+2)] == 'O'))
            return 'X';
    return 'O';
}

bool TTT::Play(char ch)
{
    if(ch == 'Y' || ch == 'y')
        return true;
    return false;
}
