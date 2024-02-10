#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(k^n)
// space complexity : o(n+1) = o(n)

int solve(int n,int k,int target){
    // base case
    if(n == 0 && target == 0) return 1;
    if(n < 0) return 0;
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;

    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += solve(n-1,k,target-i);
    }
    return ans;
}

int main(){
    int n = 1;
    int k = 6;
    int t = 3;
    int s = solve(n,k,t);
    cout << s << endl;
    return 0;
}