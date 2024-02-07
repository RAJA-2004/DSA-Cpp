#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int solve(int n,int x,int y,int z){
    // base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN; 
    }
    int a = solve(n-x,x,y,z)+1;
    int b = solve(n-y,x,y,z)+1;
    int c = solve(n-z,x,y,z)+1;
    
    int maxi = max(a,max(b,c));
    return maxi;
}

int main(){
    int n = 8;
    int x = 3;
    int y = 3;
    int z = 3;
    int value = solve(n,x,y,z);
    if(value < 0){
        value = 0;
    }
    cout << value << endl;
    return 0;
}