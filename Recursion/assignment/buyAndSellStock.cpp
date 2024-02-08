#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)

    void profit(vector<int>& prices,int i,int& miniPrice,int& maxProfit){
        // base case
        if(i==prices.size()) return;
        // sol for one case
        if(prices[i]<miniPrice) miniPrice = prices[i];
        int currProfit = prices[i]-miniPrice;
        if(currProfit > maxProfit) maxProfit = currProfit;
        // recursion
        profit(prices,i+1,miniPrice,maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        // recursive Sol
        
        // int miniPrice = INT_MAX;
        // int maxProfit = INT_MIN;
        // profit(prices,0,miniPrice,maxProfit);
        // return maxProfit;

        // iterative Sol
        // time complexity : O(n)
        // space complexity : O(1)
        int minP = INT_MAX;
        int maxP = INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minP){
                minP = prices[i];
            }
            int currP = prices[i]-minP;
            if(currP > maxP){
                maxP = currP;
            }
        }
        return maxP;
    }

int main(){
    vector<int> ans {7,1,5,3,6,4};
    int res = maxProfit(ans);
    cout << res << endl;
    return 0;
}