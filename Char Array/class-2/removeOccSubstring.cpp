#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
string removeDuplicate(string str,string part){
    int pos = str.find(part);
    while(pos!=string::npos){
        str.erase(pos,part.length());
        pos = str.find(part);
    }
    return str;
}

int main(){
    string str = "abcddababcdab";
    string part = "abc"; 
    string c = removeDuplicate(str,part);
    cout << c << endl;
    return 0;
}