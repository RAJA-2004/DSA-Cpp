#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int solve(vector<int>& days,vector<int>& costs,int i){
    // base case
    if(i>=days.size()){
        return 0;
    }

    // processing
    // cost of 1 day pass
    int cost1Day = costs[0] + solve(days,costs,i+1);

    // cost of 7 day pass
    // range of 7 day pass
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while(j < days.size() && days[j]<=passEndDay){
        j++;
    }
    int cost7Day = costs[1] + solve(days,costs,j);

    // cost of 30 day pass
    // range of 30 day pass
    passEndDay = days[i] + 30 - 1;
    j = i;
    while(j < days.size() && days[j]<=passEndDay){
        j++;
    }
    int cost30Day = costs[2] + solve(days,costs,j);

    return min(cost1Day,min(cost7Day,cost30Day));

}
int cost(vector<int>& days,vector<int>& costs){
    return solve(days,costs,0);
}

int main(){
    vector<int> days {1,4,6,7,8,20};
    vector<int> costs {2,7,15};
    int c = cost(days,costs);
    cout << c << endl;
    return 0;
}