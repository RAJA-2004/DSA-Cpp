#include <iostream>
using namespace std;

// integer part
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
    cout << "enter the number : ";
    cin >> x;
    int y = sq(x);
    cout << "sqrt of " << x <<" is : " << y << endl;

    int a;
    cout << "enter number of digits after decimal : ";
    cin >> a;
    double ans = y;
    double step = 0.1;
    for(int i=0;i<a;i++){
        for(double j=ans;j*j<=x;j=j+step){
            ans = j;
        }
        step = step / 10;
    }
    cout << "final result : " << ans << endl;
    return 0;
}