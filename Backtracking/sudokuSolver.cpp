#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

bool isSafe(vector<vector<int> >&board,int val,int i,int j){
    // row check
    for(int col=0;col<9;col++){
        if(board[i][col]==val){
            return false;
        }
    }

    // col check
    for(int row=0;row<9;row++){
        if(board[row][j]==val){
            return false;
        }
    }

    // 3*3 box 
    for(int a=0;a<9;a++){
        // i/3 => 0,1,2   => starting points of rows
        // 3*i/3 => 0,3,6 => starting points of rows
        // a/3 => 0,1,2   => provides movement within rows (downwards)
        // 3*(i/3)+(a/3)  => this line will iterate all the rows of each 3*3 box
        // 
        // j/3 => 0,1,2   => staring points of col of 1 3*3 box
        // 3*j/3 => 0,3,6 => staring points of col of all 3*3 box
        // a%3 =>  0,1,2  => provides movement within cols (rightwards)
        // 3*(j/3)+(a%3)  => this line will iterate all the cols of each 3*3 box

        if(board[3*(i/3)+(a/3)][3*(j/3)+(a%3)]==val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int> >&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            // check empty cell
            if(board[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(board,val,i,j)){
                        board[i][j]=val;
                        // recursion
                        bool aageKaSol = solve(board);
                        if(aageKaSol==true){
                            return true;
                        }else{
                            // backtracking
                            board[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int> > board(9,vector<int>(9,0));
    board[0][0] = 4;
    board[0][1] = 5;
    board[1][2] = 2;
    board[1][4] = 7;
    board[1][6] = 6;
    board[1][7] = 3;
    board[2][7] = 2;
    board[2][8] = 8;
    board[3][3] = 9;
    board[3][4] = 5;
    board[4][2] = 6;
    board[4][1] = 8;
    board[4][6] = 2;
    board[5][1] = 2;
    board[5][3] = 6;
    board[5][6] = 7;
    board[5][7] = 5;
    board[6][6] = 4;
    board[6][7] = 7;
    board[6][8] = 6;
    board[7][1] = 7;
    board[7][4] = 4;
    board[7][5] = 5;
    board[8][2] = 8;
    board[8][5] = 9;

    if(solve(board)){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}