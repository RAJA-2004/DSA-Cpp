#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs){
    // map with sorting
    map<string,vector<string>>mp;
    for(auto str : strs){
        string s = str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
    }
    vector<vector<string>> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
    }
    
    return ans;
}
int main(){
    vector<string> str = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans;
    ans = groupAnagrams(str);
    return 0;
}