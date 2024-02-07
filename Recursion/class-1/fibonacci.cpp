#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(2^n)
// space complexity : o(n)

int fibo(int n){
    // base case
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    // recursion
    return fibo(n-1)+fibo(n-2);
}

int main(){

    // 0 1 1 2 3 5 8 13 21 ....

    int a = 5;
    int c = fibo(a);
    cout << a << " term is : " << c << endl;

    return 0;
}