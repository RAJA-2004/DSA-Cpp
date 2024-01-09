#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = 9;
    int x = 0;
    int y = size-1;
    while(y>x){
        
        // using TEMP
        // int temp = arr[x];
        // arr[x] = arr[y];
        // arr[y] = temp;

        // using + -
        // arr[x] = arr[x]+arr[y];
        // arr[y] = arr[x]-arr[y];
        // arr[x] = arr[x]-arr[y];

        // using XOR
        // arr[x] = arr[x]^arr[y];
        // arr[y] = arr[x]^arr[y];
        // arr[x] = arr[x]^arr[y];

        // using swap function
        swap(arr[x],arr[y]);

        x++;
        y--;
    }
    
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}