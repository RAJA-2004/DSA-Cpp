#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(n)
// space complexity : o(n)

int fact(int n){
    // base case
    if(n<=1){
        return 1;
    }
    // recursion : function calling itself
    return n*fact(n-1);
}

int main(){
    int a = 5;
    int b = fact(a);
    cout << b << endl;
    return 0;
}