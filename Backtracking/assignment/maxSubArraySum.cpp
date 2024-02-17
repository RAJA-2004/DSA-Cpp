#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int solve(vector<int>& ans,int start,int end){
    // base case
    if(start == end){
        return ans[start];
    }

    int mid = start + ((end-start)>>1);

    // left max sum & right max sum
    int leftMaxSum = solve(ans,start,mid);
    int rightMaxSum = solve(ans,mid+1,end);

    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int leftBorderSum = 0, rightBorderSum = 0;

    // max left border sum
    for(int i=mid;i>=start;i--){
        leftBorderSum+=ans[i];
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }

    // max right border sum
    for(int j=mid+1;j<=end;j++){
        rightBorderSum += ans[j];
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }

    // crossBorderSum
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(crossBorderSum, max(leftMaxSum,rightMaxSum));
}

int maxSum(vector<int>& ans){
    return solve(ans,0,ans.size()-1);
}

int main(){
    vector<int> ans{-2,1,-3,4,-1,2,1,-5,4};
    int sum = maxSum(ans);
    cout << sum << endl;
    return 0;
}