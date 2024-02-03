#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(log n)
int fastExponent(int a,int b){
    int ans = 1;
    while(b>0){
        if(b & 1){
            ans*=a;
        }
        a*=a;
        b >>= 1; // b = b/2
    }
    return ans;
}

// time complexity : o(n)
int solwExpo(int a,int b){
    int ans = 1;
    while(b--){
        ans*=a;
    }
    return ans;
}

int main(){
    cout << solwExpo(5,4) << endl;
    cout << fastExponent(5,4) << endl;
    return 0;
}