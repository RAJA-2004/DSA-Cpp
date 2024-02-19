#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(n!)

void print(string& s,int i){
    // base
    if(i>=s.length()){
        cout << s << " ";
        return;
    }
    // processing
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        // recursion
        print(s,i+1);
        // backtracking -> why this -> to recreate the original string

        swap(s[i],s[j]);
    }
}

int main(){
    string a = "abc";
    int i = 0;
    print(a,i);
    return 0;
}