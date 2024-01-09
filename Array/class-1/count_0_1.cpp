#include <iostream>
using namespace std;
int count(int arr[],int size,int key){
    int count = 0;
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            count++;
        }
    }
    return count;
}
int main(){
    int arr[] = {1,0,1,1,1,0,1,0};
    int size = 8;
    int key;
    cin >> key;
    int x = count(arr,size,key);
    cout << "count of " << key << " : " << x << endl;
    return 0;
}