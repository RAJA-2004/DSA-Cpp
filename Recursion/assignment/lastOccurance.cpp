#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solveLeftToRight(string& s,int i,int& ans,char ch){
    // base case
    if(i<0){
        return;
    }
    // processing
    if(s[i]==ch){
        ans = i;
        return;
    }
    // recursion
    solveLeftToRight(s,i-1,ans,ch);
}

void solveRightToLeft(string& s,int i,int& ans,char ch){
    // base case
    if(i>=s.length()){
        return;
    }
    // processing
    if(s[i]==ch){
        ans = i;
    }
    // recursion
    solveRightToLeft(s,i+1,ans,ch);
}

int main(){
    string s = "rajaa";
    char target = 'a';
    int i=0;
    int ans = -1;
    solveRightToLeft(s,i,ans,target);
    solveLeftToRight(s,s.length()-1,ans,target);
    cout << ans << endl;
    return 0;
}