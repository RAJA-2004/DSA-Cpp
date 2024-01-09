#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size = 9;
    int x = arr[0];
    int y = arr[size-1];
    while(y>=x){
        if(x==y){
            cout << x;
        }
        else{
            cout << x << " ";
            cout << y << " ";
        }
        x++;
        y--;
    }
    cout << endl;
    return 0;
}