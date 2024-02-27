#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void sub(string& s,string t,int i,vector<string>& ans){
    if(i>=s.length()){
        // cout << t << endl;
        // store the output
        ans.push_back(t);
        return;
    }
    // exclude
    sub(s,t,i+1,ans);
    // include 
    t.push_back(s[i]);
    sub(s,t,i+1,ans);
} 



int main(){
    string a = "ab";
    string t = "";
    vector<string> ans;
    int i = 0 ;
    sub(a,t,i,ans);
    for(auto val : ans){
        cout << val << endl;
    }
    return 0;
}