#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                // ya tho ek i++ krke check kro
                // ya fir j-- krke check kro
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
        }
        return true;
    }

int main(){
    string str = "abca";
    cout << validPalindrome(str) << endl;
    return 0;
}