#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

map<int,string>mp = {
    {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}
};

void solve(string digits,vector<string> &ans,string str,int i){
    // base case
    if(i>=digits.length()){
        ans.push_back(str);
        return;
    }
    // processing
    int digit = digits[i] - '0';
    string s = mp[digit];
    for(int j=0;j<s.length();j++){
        char ch = s[j];
        str.push_back(ch);
        solve(digits,ans,str,i+1);
        str.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string str;
    int i = 0;
    solve(digits,ans,str,i);
    return ans;
}

int main(){
    vector<string> ans;
    string str = "23";
    ans = letterCombinations(str);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}