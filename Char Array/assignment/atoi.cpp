
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int atoiFunction(string s){
    int num = 0 , i=0 , sign = 1;
    while(s[i]==' '){
        i++;
    }
    if(i<s.size() && (s[i]=='-' || s[i]=='+')){
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }
    while(isdigit(s[i]) && i<s.size()){
        if(num / 10 > INT_MAX || num == INT_MAX / 10 && s[i] > '7'){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + s[i] - '0';
        i++;
    }
    return sign*num;
}

int main(){
    string s = "00000067";
    int a = atoiFunction(s);
    cout << a << endl;
    return 0;
}