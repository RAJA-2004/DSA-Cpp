#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,55,6,7,8,9,10};
    int size = 10;

    // INT_MIN is minimum possible number
    int max = INT_MIN;
    
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout << "max number is : " << max << endl;
    return 0;
}