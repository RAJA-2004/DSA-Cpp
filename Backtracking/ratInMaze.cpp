#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int arr1[4] = {0,0,-1,1};
int arr2[4] = {-1,1,0,0};
int arr3[4] = {'L','R','U','D'};

bool isSafe(int i,int j,int row,int col,vector<vector<int> >& maze,vector<vector<bool> >& visited){
    if((i>=0 && i<row) && (j>=0 && j<col) && (maze[i][j]==1) && (visited[i][j]==false)){
        return true;
    }else{
        return false;
    }
}

// void solveMaze(vector<vector<int> >& maze,int row,int col,int i,int j,vector<vector<bool> >& visited,vector<string>& path,string output){
//     // base case
//     if(i == row-1 && j == col-1){
//         path.push_back(output);
//         return;
//     }
//     // processing
//     // down -> [i+1][j]
//     if(isSafe(i+1,j,row,col,maze,visited)){
//         visited[i+1][j] = true;
//         solveMaze(maze,row,col,i+1,j,visited,path,output+'D');
//         // backtracking
//         visited[i+1][j] = false;
//     }

//     // left -> [i][j-1]
//     if(isSafe(i,j-1,row,col,maze,visited)){
//         visited[i][j-1] = true;
//         solveMaze(maze,row,col,i,j-1,visited,path,output+'L');
//         // backtracking
//         visited[i][j-1] = false;
//     }

//     // right -> [i][j+1]
//     if(isSafe(i,j+1,row,col,maze,visited)){
//         visited[i][j+1] = true;
//         solveMaze(maze,row,col,i,j+1,visited,path,output+'R');
//         // backtracking
//         visited[i][j+1] = false;
//     }

//     // up -> [i-1][j]
//     if(isSafe(i-1,j,row,col,maze,visited)){
//         visited[i-1][j] = true;
//         solveMaze(maze,row,col,i+1,j,visited,path,output+'U');
//         // backtracking
//         visited[i-1][j] = false;
//     }

// }

void solveMaze(vector<vector<int> >& maze,int row,int col,int i,int j,vector<vector<bool> >& visited,vector<string>& path,string output){
    
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return;
    }

    for(int k=0;k<4;k++){
        int newX = i + arr1[k];
        int newY = j + arr2[k];
        char dir = arr3[k];
        if(isSafe(newX,newY,row,col,maze,visited)){
            visited[newX][newY] = true;
            solveMaze(maze,row,col,newX,newY,visited,path,output+dir);
            visited[newX][newY]=false;
        }
    }
}

int main(){
    vector<vector<int> > maze{{1,0,0},
                            {1,1,0},
                            {1,1,1}
                        };

    if(maze[0][0]==0){
        cout << "not path exists" << endl;
    }
    
    int row = maze.size();
    int col = maze[0].size();
    vector<vector<bool> > visited(row,vector<bool>(col,false));
    // source 
    visited[0][0] = true;
    vector<string> path;
    string output = "";

    solveMaze(maze,row,col,0,0,visited,path,output);

    for(auto values : path){
        cout << values << " ";
    }
    return 0;
}