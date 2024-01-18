#include <iostream>
using namespace std;
int sq(int target){
    int start = 0;
    int ans = -1;
    int end = target;
    int mid = start + (end-start)/2;
    // 0 1 2 3 4 5 6 7 
    while(start<=end){
        if (mid*mid == target){
            return mid;
        }
        if(mid*mid < target){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        
        mid = start + (end-start)/2;
    }
    return ans;
}
int main(){
    int x;
    cin >> x;
    int y = sq(x);
    cout << "sqrt of " << x <<" is : " << y << endl;
    return 0;
}