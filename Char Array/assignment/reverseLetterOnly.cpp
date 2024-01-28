#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;


string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(isalpha(s[i])&&isalpha(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isalpha(s[i])){
                i++;
            }else{
                j--;
            }
        }
        return s;
    }

int main(){
    string s = "ab-cd";
    s = reverseOnlyLetters(s);
    cout << s << endl;
    return 0;
}