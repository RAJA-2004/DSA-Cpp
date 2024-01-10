#include <iostream>
#include <vector>
using namespace std;

void sum(int arr[][3],int rows,int col){
    int min = INT_MAX;
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]<min){
                min = arr[i][j];
            }
        }
    }
    cout << "min element : " << min << " ";
}
int main(){
    int arr[3][3] = {{1,2,0}
                    ,{4,15,-6}
                    ,{7,8,9}};
    int rows = 3;
    int col = 3;
    sum(arr,rows,col);
    return 0;
}