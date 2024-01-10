#include <iostream>
#include <vector>
using namespace std;
// 2D,3D,4D.... only 1st [] empty rest sbmai value deni hogi
void search(int arr[][3],int rows,int col,int key){
    int flag = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(key==arr[i][j]){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        cout << "found" << endl;
    }else{
        cout << "not found" << endl;
    }
}
int main(){
    int arr[3][3] = {{1,2,3}
                    ,{4,5,6}
                    ,{7,8,9}};
    int rows = 3;
    int col = 3;
    int key;
    cin >> key;
    search(arr,rows,col,key);
    return 0;
}