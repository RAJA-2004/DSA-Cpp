#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<long long int>& ans,long long int p,long long int l,long long int mid){
    long long count = 0;
    for(long long int i=0;i<ans.size();i++){
        long long int j=1;
        long long int c = ans[i];
        long long int sum = 0;
        while(true){
            if(sum+(j*c)<=mid){
                count++;
                sum += j*c;
                j++;
            }else{
                break;
            }
        }
        if(count>=p){
            return true;
        }
    }
    return false;
}
int prata(vector<long long int>& ans,long long int p,long long int l){
    long long int start = 0;
    long long int n = ans.size();
    long long int end = *max_element(ans.begin(),ans.end())*(p*(p+1)/2);
    long long int a = -1;
    while(start<=end){
        long long int mid = start + (end-start)/2;
        if(isPossible(ans,p,l,mid)){
            a = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return a;
}
int main(){
    long long int n;
    cin >> n;
    
    while(n--){
        long long int p,l;
        cin >> p >> l;
        vector<long long int> ans;
        while(l--){
            long long int a;
            cin >> a;
            ans.push_back(a);
        }
        cout << prata(ans,p,l) << endl;
    }
    
    // for(auto values : ans){
    //     cout << values << " ";
    // }
    return 0;
}