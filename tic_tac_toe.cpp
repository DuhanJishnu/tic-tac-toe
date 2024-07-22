#include <iostream>
using namespace std;

// Making a 2-D array and inserting column name 
char space[3][3] ={{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
int row, column;
char token = 'X';
string n1, n2;
bool tie = false;

void printBoard()
{
    // Printing the "Tic Tac Toe" 
    cout<< "    |    |   "  <<endl;
    cout<< " "<<space[0][0]<<"  | "<<space[0][1]<<"  | "<<space[0][2]<<endl; 
    cout<< "____|____|____" <<endl;
    cout<< "    |    |   "  <<endl;
    cout<< " "<<space[1][0]<<"  | "<<space[1][1]<<"  | "<<space[1][2]<<endl; 
    cout<< "____|____|____" <<endl; 
    cout<< "    |    |   "  <<endl;
    cout<< " "<<space[2][0]<<"  | "<<space[2][1]<<"  | "<<space[2][2]<<endl; 
    cout<< "    |    |   "  <<endl;
}

void playerTurn(){
    int digit;
    if (token == 'X'){
        cout << n1 << " Please Enter Place: ";
        cin >> digit;
    }
    else if (token == 'O'){
        cout << n2 << " Please Enter Place: ";
        cin >> digit;
    }
    if (digit == 1) {row = 0; column = 0;}
    else if (digit == 2) {row = 0; column = 1;}
    else if (digit == 3) {row = 0; column = 2;}
    else if (digit == 4) {row = 1; column = 0;}
    else if (digit == 5) {row = 1; column = 1;}
    else if (digit == 6) {row = 1; column = 2;}
    else if (digit == 7) {row = 2; column = 0;}
    else if (digit == 8) {row = 2; column = 1;}
    else if (digit == 9) {row = 2; column = 2;}
    else {
        cout << "Invalid Digit !!!" << endl;
        playerTurn();
    }

    if(token == 'X' && space[row][column] !='X' && space[row][column] != 'O'){
        space[row][column] = 'X';
        token = 'O';
    }
    else if(token == 'O' && space[row][column] !='X' && space[row][column] != 'O'){
        space[row][column] = 'O';
        token = 'X';
    }
    else{
        cout << "This Space is not EMPTY" << endl;
        playerTurn();
    }
}

bool checkWin(){
    for(int i = 0; i < 3; i++){
        // checking rows and columns
        if((space[i][0] == space[i][1] && space[i][1] == space[i][2]) || 
           (space[0][i] == space[1][i] && space[1][i] == space[2][i]))
        {
            return true;
        }
    }
    // checking diagonals
    if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || 
       (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }

    // checking if game is still going on 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }

    tie = true;
    return true;
}
 
int main()
{
    cout << "\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout << "\n\t\t\t\tFOR 2 PLAYERS\n";
    cout << "Enter Name of Player 1:  ";
    getline(cin, n1);
    cout << "Enter Name of Player 2:  ";
    getline(cin, n2);

    cout << "\t\t\t" << n1 << "[X]\t\t" << n2 << "[O]\n\n";
    cout << "\t" << n1 << " is player 1 so he/she will play first" << endl;
    cout << "\t" << n2 << " is player 2 so he/she will play second" << endl;

    while(!checkWin())
    {
        printBoard();
        playerTurn();
    }

    printBoard(); // print the final board
    if(token == 'X' && tie == false){
        cout << n2 << " WINS !!!" << endl;
    }
    else if(token == 'O' && tie == false){
        cout << n1 << " WINS !!!" << endl;
    }
    else{
        cout << "It's a DRAW" << endl;
    }

    return 0;
}
