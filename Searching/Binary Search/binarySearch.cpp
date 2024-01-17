#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearchs(int arr[],int target,int size){
    int start = 0;
    int end = size-1;

    // ISSUE -> integer overflow
    // int mid = (start+end)/2;
    // SOLUTION
    int mid = start + (end - start)/2;
    
    while(start <= end){
        if(arr[mid]==target){
            // found
            return mid;
        }
        else if(target < arr[mid]){
            // left search
            end = mid-1;
        }
        else{
            // right search
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){

    // USING STL
    vector<int> v{2,4,5,8,9};
    int arr[] = {1,2,3,4,5,6,7};
    int N = 7;
    int key;
    cin >> key;

    // for VECTOR
    if(binary_search(v.begin(),v.end(),key)){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }

    // for ARRAY
    if(binary_search(arr,arr+N,key)){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }

    // int arr[5] = {2,5,6,8,9};
    // int N = 5;
    // int key = 2;
    // int x = binarySearch(arr,key,N);
    // if(x==-1){
    //     cout << "not found" <<endl;
    // }
    // else{
    //     cout << "found at index " << x << endl;
    // }
    return 0;
}