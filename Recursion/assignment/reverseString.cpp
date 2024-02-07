#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(n/2) = o(n)
// complexity : o[(n/2)+1] = o(n)

void rev(string& s,int i,int j){
    // base case
    if(i>j){
        return;
    }
    // processing
    swap(s[i],s[j]);
    // recursion
    rev(s,i+1,j-1);
}

int main(){
    string s = "raja";
    rev(s,0,s.length()-1);
    cout << s << endl;
    return 0;
}