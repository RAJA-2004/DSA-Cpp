#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// euclid algorithm
int gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;

    while(a>0 && b>0){
        if(a>b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    return a == 0 ? b : a;
}
int lcm(int a,int b){
    int c = gcd(a,b);
    return (a*b)/c;
}
int main(){
    int a = lcm(2,12);
    cout << a << endl;
    return 0;
}