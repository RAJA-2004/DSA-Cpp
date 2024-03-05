#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;


bool isVowel(char ch){
        ch = tolower(ch);
        return ch=='a' || ch =='e' || ch == 'i' || ch =='o' || ch == 'u';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(isVowel(s[i]) && isVowel(s[j])){
            swap(s[i],s[j]);
            i++;
            j--;
            }
            else if(!isVowel(s[j])){
                j--;
            }
            else{
                i++;
            }
        }
        return s;
    }

int main(){
    string s = "ae-i-ou";
    s = reverseVowels(s);
    cout << s << endl;
    return 0;
}