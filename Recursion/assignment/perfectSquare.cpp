#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int solve(int n){
    // base case
    if(n==0) return 1;
    if(n<0) return 0;

    // processing
    int i=1;
    int end = sqrt(n);
    int ans = INT_MAX;
    while(i <=end){
        int square = i*i;
        int a = 1 + solve(n - square);
        if(a < ans){
            ans = a;
        }
        i++;
    }
    return ans;
}

int numSquares(int n) {
    return solve(n)-1;
}

int main(){
    int n = 13;
    int a = numSquares(n);
    cout << a << endl;
    return 0;
}