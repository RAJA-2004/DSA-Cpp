#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
    // 2 solutions
public:
    int lowerBound(vector<int>& arr, int x){
        int start = 0;
        int end = arr.size()-1;
        // if x is not present in array last element will be lower bound 
        int ans = end;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid]>=x){
                ans = mid;
                end = mid-1;
            }
            else if(arr[mid]>x){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }

    vector<int> usingBS(vector<int>& arr, int k, int x) {
        // find closest to x -> lower bound
        int high = lowerBound(arr,x);
        int low = high-1;
        while(k--){
            if (low<0){
                high++;
            }
            else if(high >= arr.size()){
                low--;
            }
            else if(x-arr[low]>arr[high]-x){
                high++;
            }
            else{
                low--;
            }
        }
        return vector<int>(arr.begin()+low+1,arr.begin()+high);
    }

    vector<int> usingTwoPTR(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high-low>=k){
            if(x-arr[low] > arr[high]-x){
                low++;
            }
            else{
                high--;
            }
        }

        // vector<int>ans;
        // for(int i=low;i<=high;i++){
        //     ans.push_back(arr[i]);
        // }
        // return ans;

        // STL trick const space
        return vector<int>(arr.begin()+low,arr.begin()+high+1);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return usingTwoPTR(arr,k,x);
        return usingBS(arr,k,x);
    }
};
int main(){
    vector<int>ans{4,9,14,16,29};
    int k = 2;
    int t = 14;
    Solution s1;
    vector<int> res=s1.findClosestElements(ans,k,t);
    for(auto values : res){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}