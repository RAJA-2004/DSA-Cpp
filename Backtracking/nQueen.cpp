#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;


// we used maps bcz it converted o(n) to o(1)

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;

void printBoard(vector<vector<char> > &board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

// time complexity of if safe function can be modified and it can be reduced o(1)

bool isSafe(vector<vector<char> > &board,int row,int col,int n){
    int i = row;
    int j = col;

    if(rowCheck[row] == true){
        return false;
    }

    if(upperLeftDiagonalCheck[n-1+col-row]==true){
        return false;
    }

    if(bottomLeftDiagonalCheck[col+row]==true){
        return false;
    }

    return true;

    // here in while loops time complexity was o(n)

    // while(j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     j--;
    // }
    // i=row;
    // j=col;
    // while(i>=0 && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }
    // i=row;
    // j=col;
    // while(i<n &&j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    // return true;
}

void solveBoard(vector<vector<char> > &board,int col,int n){
    if(col>=n){
        printBoard(board,n);
        return;
    }
    for(int row = 0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            bottomLeftDiagonalCheck[row+col] = true;
            
            solveBoard(board,col+1,n);
            
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            bottomLeftDiagonalCheck[row+col] = false;
        }
    }
}

int main(){
    int n;
    cout << "enter board size : ";
    cin >> n;
    cout << endl << endl;
    vector<vector<char> > board(n,vector<char>(n,'-'));
    int col = 0;
    solveBoard(board,col,n);
    return 0;
}