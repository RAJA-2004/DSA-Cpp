#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int first(vector<int>ans,int key){
    int start = 0;
    int end = ans.size()-1;
    int mid = start + (end-start)/2;
    int a = -1;
    while(start<=end){
        if(key==ans[mid]){
            // store answer
            a=mid;
            // search left
            end = mid-1;
        }
        else if(key > ans[mid]){
            // right search
            start = mid+1;
        }
        else if(key < ans[mid]){
            // left search
            end = mid-1;
        }

        // UPDATE MID
        mid = start + (end - start)/2;
    }
    return a;
}
int main(){
    vector<int> ans{1,2,2,2,2,2,4,4,4};

    // USING STL
    auto x = lower_bound(ans.begin(),ans.end(),2);
    cout << "lower bound / first occurance : " << x-ans.begin() << endl;

    // WITHOUT STL

    int a = first(ans,2);
    if(a!=-1){
        cout << "first occurance at : " << a << endl;
    }
    else{
        cout << "not found" << endl;
    }
    return 0;
}