
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin >> ans[i];
    }
    vector<int> res;
    priority_queue<int,vector<int>,greater<int> > pq;

    for(int i=0;i<n;i++){
        pq.push(ans[i]);
        if(pq.size()>k){
            res.push_back(pq.top());
            pq.pop();
        }
    }
    while(pq.size()>0){
        res.push_back(pq.top());
        pq.pop();
    }
    for(int i=0;i<n;i++){
        cout << res[i] <<  " ";
    }
    cout << endl;
    return 0;
}