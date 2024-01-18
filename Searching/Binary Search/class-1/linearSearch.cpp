#include <iostream>
using namespace std;
int main(){
    int arr[5] = {3,4,2,1,5};
    int key = 4;
    for(int i=0;i<5;i++){
        if(arr[i]==key){
            cout << "found at " << i << " index" << endl;
        }
    }
    return 0;
}