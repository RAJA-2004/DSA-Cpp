#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

bool isMatching(string& s,int si, string& p,int pi){
    // base case
    if(si==s.size() && pi==p.size()){
        return true;
    }
    if(si==s.size() || pi < p.size()){
        while(pi < p.size()){
            if(p[pi]!='*') return false;
            pi++;
        }
        return true;
    }

    // processing
    if(s[si]==p[pi] || '?'==p[pi]){
        return (s,si+1,p,pi+1);
    }
    if(p[pi]=='*'){
        // case 1
        bool caseA = isMatching(s,si,p,pi+1);
        // case 2
        bool caseB = isMatching(s,si+1,p,pi);

        return caseA || caseB;
    }
    return false;
}

bool isMatch(string& s, string& p) {
    int si = 0;
    int pi = 0;
    return isMatching(s,si,p,pi);
}

int main(){
    string s = "cb";
    string p = "?a";
    if(isMatch(s,p)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}