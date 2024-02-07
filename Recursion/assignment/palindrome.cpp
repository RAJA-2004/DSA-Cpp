#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

bool palindrome(string& s,int i,int j){
    if(i>=j){
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }
    return palindrome(s,i+1,j-1);
}

int main(){
    string s = "malayalam";
    bool fun = palindrome(s,0,s.length()-1);
    cout << fun << endl;
    return 0;
}