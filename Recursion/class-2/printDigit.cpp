#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void print(int n){
    // base case
    if(n==0){
        return;
    }
    // processing
    int a = n%10;
    cout << a << " ";
    // recursion
    return print(n/10);
}

int main(){
    int a = 200;
    print(a);
    return 0;
}