#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int total(vector<int>ans,int key){
    auto x = lower_bound(ans.begin(),ans.end(),key);
    auto y = upper_bound(ans.begin(),ans.end(),key);
    auto z = x-ans.begin();
    auto a = y-ans.begin();
    return a-z;
}
int main(){
    vector<int> ans{1,2,3,4,4,4,4};
    int key = 4;
    int res = total(ans,key);
    cout << "total occurance : " << res << endl;
    return 0;
}