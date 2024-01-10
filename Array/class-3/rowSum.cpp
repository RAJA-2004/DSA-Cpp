#include <iostream>
#include <vector>
using namespace std;
// 2D,3D,4D.... only 1st [] empty rest sbmai value deni hogi
void sum(int arr[][3],int rows,int col){
    for(int i=0;i<rows;i++){
        int sum = 0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout << sum << " ";
    }
}
int main(){
    int arr[3][3] = {{1,2,3}
                    ,{4,5,6}
                    ,{7,8,9}};
    int rows = 3;
    int col = 3;
    sum(arr,rows,col);
    return 0;
}