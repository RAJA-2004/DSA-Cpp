#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

string zigzag(string s,int numRows){
    if(numRows == 1){
        return s;
    }
    int row = 0;
    int i = 0;
    bool direction = 1;
    vector<string>ans(numRows);
        while(true){
            if(direction){
                while(i<s.size() && row<numRows){
                    // top to bottom
                    ans[row++].push_back(s[i++]);
                    // change the row
                }
                row = numRows - 2;
            }else{
                while(i<s.size() && row>=0){
                    // bottom to top
                    ans[row--].push_back(s[i++]);
                    // change the row
                }
                row = 1;
            }
            if(i>=s.size()) break;
            direction = !direction;
        }
    string str = "";
    for(int i=0;i<ans.size();i++){
        str += ans[i];
    }
    return str;
}

int main(){
    string s = "ABCDEF";
    int numRows = 3;
    string y = zigzag(s,numRows);
    cout << y << endl;
    return 0;
}