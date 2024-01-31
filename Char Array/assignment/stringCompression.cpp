#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int st(vector<string>& s){
    int count = 1;
    int index = 0;
    int prev = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]==s[prev]){
            count++;
        }else{
            s[index++] = s[prev];
            if(count > 1){
                string str = to_string(count);
                for(char c : str){
                    s[index++] = c;
                }
                count = 1;
                prev = i;
            }
        }
    }
    s[index++] = s[prev];
    if(count > 1){
        string str = to_string(count);
            for(char c : str){
                s[index++] = c;
            }
    }
    return index;
}

int main(){
    vector<string> s {"a","a","b","b","c","d","e","e"};
    int size = st(s);
    cout << size << endl;
    return 0;
}