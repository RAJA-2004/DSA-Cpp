#include <iostream>
#include <vector>
using namespace std;
vector<int> fac(int N){
    vector<int>ans;
    ans.push_back(1);
    int carry = 0;
    for(int i=2;i<=N;i++){
        for(int j=0;j<ans.size();j++){
            int x = ans[j]*i+carry;
            ans[j]=x%10;
            carry=x/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry=carry/10;
        } 
        carry=0;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int N;
    cin >> N;
    vector<int>ans = fac(N);
    for(auto values : ans){
        cout << values << " ";
    }
    return 0;
}