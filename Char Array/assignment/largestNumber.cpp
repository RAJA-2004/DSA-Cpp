#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

static bool cmp(string a,string b){
    string t1 = a+b;
    string t2 = b+a;
    return t1>t2;
}
string largestNum(vector<int>& num){
    vector<string>ans;
    for(auto s:num){
        ans.push_back(to_string(s));
    }
    sort(ans.begin(),ans.end(),cmp);
    string str = "";
    for(auto i:ans){
        str+=i;
    }
    return str;
}
int main(){
    vector<int> ans{30,3};
    string s = largestNum(ans);
    cout << s << endl;
    return 0;
}