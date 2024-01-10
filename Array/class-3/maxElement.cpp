#include <iostream>
#include <vector>
using namespace std;

void sum(int arr[][3],int rows,int col){
    int max = INT_MIN;
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]>max){
                max = arr[i][j];
            }
        }
    }
    cout << "max element : " << max << " ";
}
int main(){
    int arr[3][3] = {{1,2,3}
                    ,{4,15,6}
                    ,{7,8,9}};
    int rows = 3;
    int col = 3;
    sum(arr,rows,col);
    return 0;
}