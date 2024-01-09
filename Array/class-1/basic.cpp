#include <iostream>
using namespace std;
int main(){
    // integer array

    // without size
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "array initialised" << endl;

    // with size 2
    int ar[2] = {2,4};
    cout << "array initialised" << endl;

    // char array
    char arr1[] = {'a','b','c'};
    cout << "array initialised" << endl;

    // accessing using index
    for(int i=0;i<3;i++){
        cout << "value at index " << i << " : "<< arr[i] << endl;
    }
    // garbage value
    cout << "garbage value : " << arr[11] << endl;

    // doubles
    cout << "doubles : ";
    for(int i=0;i<3;i++){
        cout << 2 * arr[i] << endl;
    }

    // memset for repetition
    // works on char and int (ONLY 0 and -1)
    char str[] = "raja";
    memset(str,'s',sizeof(str));
    cout << str << endl;

    // indexes which are not defiend will set to 0
    int raj[10] = {1,2};
    for(int i=0;i<10;i++){
        cout << raj[i] << " ";
    }

    return 0;
}