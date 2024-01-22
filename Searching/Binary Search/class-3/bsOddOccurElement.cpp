
// all element occur even no of time except one
// occur in pair
// pair are not adjacent

// sol approach
// array : 1 1 2 2 3 3 4 4 <-  3  -> 4 4  60 60
// index : 0 1 2 3 4 5 6 7     8     9 10 11 12
//         E O E O E O E O     E     O  E  O  E

// answer always on even index
// ans -> left pattern  = E O E O
// ans -> right pattern = O E O E

#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int>ans){
    int start = 0;
    int end = ans.size()-1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(start==end){
            return start;
        }
        // ODD EVEN APPROACH
        if(mid%2==0){ 
            // even
            if(ans[mid]==ans[mid+1]){
                // right search
                // mid+2 bcz mid+1 already checked
                start = mid + 2;
            }
            else{
                // left search
                // bcz mid can also be answer as aage wala is odd index
                end = mid;
             }
        }
        else{
            // odd
            if(ans[mid-1]==ans[mid]){
                // right search
                start = mid + 1;
            }
            else{
                // left search
                // even mid(odd) even
                // not going right bcz pairing is on right of type ODD EVEN
                end = mid - 1;
            }

        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int>ans{1,1,2,2,3,3,4,4,3,60,60,4,4};
    int res = bs(ans);
    cout << "index : " << res << endl;
    cout << "value : " << ans[res] << endl;
    return 0;
}