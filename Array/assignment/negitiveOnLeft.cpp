#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>ans {-1,2,-3,4,-6};

    // SORTING APPROACH
    // sort(ans.begin(),ans.end());
    
    //  POINTER APPROACH
    int low=0;
    int i=0;
    int high=ans.size()-1;
    while(low<high){
        if(ans[i]<0){
            swap(ans[low],ans[i]);
            i++;
            low++;
        }
        else{
            swap(ans[high],ans[i]);
            high--;
        }
    }
    for(auto values:ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}