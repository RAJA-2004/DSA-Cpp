#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(string& s,string& target){
    int pos = s.find(target);
    if(pos != string::npos){
        string left = s.substr(0,pos);
        string right = s.substr(pos+target.length(),s.length());
        s = left + right;

        solve(s,target);
    }else{
        return;
    }
}

int main(){
    string s = "racecar";
    string target = "ace";
    solve(s,target);
    cout << s << endl;
    return 0;
}