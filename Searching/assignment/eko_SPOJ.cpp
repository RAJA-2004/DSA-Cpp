#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<long long int>& trees,long long int M,long long int mid){
    long long int sum = 0;
    for(long long int i=0;i<trees.size();i++){
        if(trees[i]>mid){
            sum += trees[i]-mid;
        }
    }
    return sum>=M;
}
long long int maxSawBladeHeight(vector<long long int>& trees,long long int M){
    long long int start = 0;
    long long int end = *max_element(trees.begin(),trees.end());
    long long int ans = -1;
    while(start <= end){
        long long int mid = start + (end-start)/2;
        if(isPossible(trees,M,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}
int main(){
    long long int N,M;
    cin >> N >> M;
    vector<long long int> trees;
    while(N--){
        long long int height;
        cin >> height;
        trees.push_back(height);
    }
    cout << maxSawBladeHeight(trees,M) << endl;
    return 0;
}