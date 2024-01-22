
// given an array nearly sorted :- means that if the element place in sorted array was at
// index i then in case of nearly sorted array it would be either on index 
// i-1,i,i+1

// nearly sorted array : 10 3 40 20 50 80 70
//               index :  0 1  2  3  4  5  6

//        sorted array : 3 10 20 40 50 70 80
//               index : 0  1  2  3  4  5  6

// eg 3 is on index 1 in nearly sorted array and
//         on index 0 in sorted array

// as per question 3 can be on either :- 0,1,2

#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int>ans,int target){
    int start = 0;
    int end = ans.size()-1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(ans[mid]==target){
            return mid;
        }
        if(mid+1<=ans.size() && ans[mid+1]==target){
            return mid+1;
        }
        if(mid-1>=0 && ans[mid-1]==target){
            return mid-1;
        }
        else if(ans[mid]>target){
            // -2 bcz we have already viisted mid-1 index
            end = mid-2;
        }
        else{
            // +2 bcz we have already viisted mid+ 1 index
            start = mid+2;
        }
        mid = start + (end - mid)/2;
    }
    return -1;
}
int main(){
    vector<int>ans{10,3,40,20,50,80,70};
    int target = 50;
    int res = bs(ans,target);
    cout << "found at index : " << res << endl;
    return 0;
}