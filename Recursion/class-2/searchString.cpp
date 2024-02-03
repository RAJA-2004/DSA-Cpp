#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

bool searchKey(string& s,char& key,int i){
    // base case
    if(i>=s.size()){
        return false;
    }
    // processing
    if(s[i]==key){
        return true;
    }
    // recursion
    return searchKey(s,key,i+1);
}

int search(string& s,char& key,int i){
    // base case
    if(i>=s.size()){
        return -1;
    }
    // processing
    if(s[i]==key){
        return i;
    }
    // recursion
    return search(s,key,i+1);
}

void searchIndex(string& s,char& key,int i,vector<int>&ans){
    // base case
    if(i>=s.size()){
        return;
    }
    // processing
    if(s[i]==key){
        // storing all occurance index
        ans.push_back(i);
    }
    // recursion
    return searchIndex(s,key,i+1,ans);
}
int main(){
    string s = "raja";
    char key = 'a';
    int i = 0;
    if(searchKey(s,key,i)){
        int res = search(s,key,i);
        cout << "found at index : " << res << endl;
    }else{
        cout << "not found" << endl;
    }
    vector<int>ans;
    searchIndex(s,key,i,ans);
    for(auto val : ans){
        cout << val << " ";
    }
    
    return 0;
}