#include <iostream>
#include <vector>
using namespace std;
int unique(vector<int>vrr){
    int ans = 0;
    for(int i=0;i<vrr.size();i++){
        ans = ans^vrr[i];
    }
    return ans;
}
int main(){
    vector<int>vrr;
    for(int i=0;i<9;i++){
        int a;
        cin >> a;
        vrr.push_back(a);
    }
    int ans = unique(vrr);
    cout << ans;
    return 0;
}