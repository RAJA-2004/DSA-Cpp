#include <iostream>
#include <vector>
using namespace std;
bool bs(int arr[][4],int target,int m,int n){
    int start = 0;
    int end = m*n-1;
    int mid = start+(end-start)/2;
    int rowIndex = mid/n;
    int colIndex = mid%n;
    while(start <= end){
        if(arr[rowIndex][colIndex]==target){
            return true;
        }
        else if(arr[rowIndex][colIndex]<target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return false;
}
int main(){
    int row = 3;
    int col = 4;
    
    // int arr[3][4]={{1,2,3,4},
    //                {5,6,7,8},
    //                {9,10,12,13}};

    int arr[3][4];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> arr[i][j];
        }
    }

    bool ans = bs(arr,6,3,4);
    if(ans==1){
        cout << "element found" << endl;
    }else{
        cout << "element not found" << endl;
    }
    
    // int start = 0;
    // int end = (row*col)-1;
    // int mid = start+(end-start)/2;
    // int rowIndex = mid/col;
    // int colIndex = mid%col;

    // cout << "start index : " << start << " value : " << arr[start][start] << endl;
    // cout << "end index : " << end << " value : " << arr[row-1][col-1] << endl;
    // cout << "mid index : " << mid << " value : " << arr[rowIndex][colIndex] << endl;


    return 0;
}