#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void revCount(int n){
    // base case
    if(n==0){
        return;
    }
    cout << n << " ";
    // function calling itself
    revCount(n-1);
}

void forCount(int n){
    // base case
    if(n==0){
        return;
    }

    // function calling itself
    forCount(n-1);

    cout << n << " ";
}

int main(){
    revCount(5);
    cout << endl;
    forCount(5);
    return 0;
}