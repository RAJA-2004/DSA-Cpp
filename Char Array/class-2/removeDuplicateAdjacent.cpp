#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
string removeDuplicate(string str){
    string ch;
    for(int i=0;i<str.length();i++){
        if(ch.length()>0){
            if(str[i]!=ch[ch.length()-1]){
                ch.push_back(str[i]);
            }else{
                ch.pop_back();
            }
        }
        else{
            ch.push_back(str[i]);
        }
    }
    return ch;
}

int main(){
    string str = "abbacd"; 
    string c = removeDuplicate(str);
    cout << c << endl;
    return 0;
}