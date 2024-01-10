#include <iostream>
#include <vector>
using namespace std;
void transp(int arr[][3],int transArray[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            transArray[j][i]=arr[i][j];
        }
    }
}
int main(){
    int arr[3][3] = {{1,2,3}
                    ,{4,5,6}
                    ,{7,8,9}};
    int transArray[3][3];
    transp(arr,transArray); 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){ 
            cout << transArray[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}