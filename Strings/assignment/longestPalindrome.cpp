#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

string isPalindrome(string s,int i,int j){
        string str;
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                str = s.substr(i,j-i+1);
                i--;
                j++;
            }
        }
        return str;
    }
    string longestPalindrome(string s) {
        string ans1="";
        string ans2="";
        int oddSize = INT_MIN;
        int evenSize = INT_MIN;
        for(int i=0;i<s.size();i++){
            // odd
            
            string str = isPalindrome(s,i,i);
            if(str.size()>oddSize){
                oddSize = str.size();
                ans1 = str;
            }

            // even
            
            string strr=isPalindrome(s,i,i+1);
            if(strr.size()>evenSize){
                evenSize = strr.size();
                ans2 = strr;
            }
        }
        if(evenSize > oddSize){
            return ans2;
        }else{
            return ans1;
        }

    }


int main(){
    string s = "babad";
    string d = longestPalindrome(s);
    cout << d << endl;
    return 0;
}