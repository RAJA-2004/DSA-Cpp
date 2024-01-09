#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,55,6,7,8,9,10};
    int size = 10;

    // INT_MAX is maximum possible number
    int min = INT_MAX;
    
    for(int i=0;i<size;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    cout << "min number is : " << min << endl;
    return 0;
}