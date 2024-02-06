#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
bool checkSorted(vector<string>& s,int i){
    // base case
    if(i==s.size()-1){
        return true;
    }
    // processing
    if(s[i]>s[i+1]){
        return false;
    }
    // recursion call
    return checkSorted(s,i+1);
}
int main(){
    vector<string> s{"a","b","c"};
    if(checkSorted(s,0)){
        cout << "sorted" << endl;
    }else{
        cout << "not sorted" << endl;
    }
    return 0;
}