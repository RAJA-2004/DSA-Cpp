#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int climb(int n){
    // base case
    if(n<=1){
        return 1;
    }
    // recursion
    return climb(n-1)+climb(n-2);
}

int main(){

    int a = 5 ;
    int c = climb(a);
    cout <<"toal ways to reach stair " << a << " : " << c << endl;

    return 0;
}