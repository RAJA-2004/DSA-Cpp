#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

bool anagram(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }

    // hasing approach
    int hash[256] = {0}; // 256 bcz it is the total number of ASCII values
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        hash[t[i]]--; 
    }
    for(int i=0;i<256;i++){
        if(hash[i]!=0){
            return false;
        }
    }
    return true;


    // sorting approach
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());
    // int i=0;
    // int n = t.size();
    // while (n--)
    // {
    //     if(s[i]==t[i]){
    //         i++;
    //     }else{
    //         return false;
    //     }
    // }
    // return true;
    
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    if(anagram(s,t)==1){
        cout << "anagram";
    }else{
        cout << "not anagram";
    }
    return 0;
}