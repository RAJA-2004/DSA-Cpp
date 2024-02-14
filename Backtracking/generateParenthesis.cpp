#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(vector<string> &ans,int open, int close,string str){
    // base case
    if(open == 0 && close == 0){
        ans.push_back(str);
        return;
    }
    // processing
    // include open brackets 
    if(open > 0){
        str.push_back('(');
        solve(ans,open-1,close,str);
        // backtracking
        str.pop_back();
    }
    // include close brackets
    if(close > open){
        str.push_back(')');
        solve(ans,open,close-1,str);
        // backtracking
        str.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    string str = "";
    solve(ans,n,n,str);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}