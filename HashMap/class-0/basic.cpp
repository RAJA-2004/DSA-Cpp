#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include<map>
using namespace std;

int main(){
    map<int,char> m;
    m[0]='a';
    m[1]='b';
    m[2]='c';
    m[3]='d';
    
    cout << m[2] << endl;
    return 0;
}